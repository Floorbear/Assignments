
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <cuda.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_CRVS	1024		// 블록의 수 = 만들려는 베지에 곡선의 수 
#define	NUM_THREADS	32
#define MAX_SAMPLES 256

//병렬 Child를 쓸거면
//프로젝트 속성 Cuda C++ Common에서 Generate ~를 예로 한다.

// 2차 베지에 곡선을 표현하는 구조체
struct BzrCrv {
	float2 CP[3];	// 제어점 3개 배열
	int nVertices;	// 곡선 위의 샘플링 점의 수 (4 ~ 256)
	float2* vertexPos;	// 곡선 위의 샘플링된 점의 좌표.. 동적 할당한다.
};


__global__ void computerBzrCrvs_Parent(BzrCrv* Crvs, int NumCrvs);
__global__ void computeBzrCrvs_Child(int _i, BzrCrv* Crvs, int _numSamples);
__global__ void freeVertexMem(BzrCrv* Crv, int numCrvs);


__device__ float2 operator +(float2 a, float2 b)
{
	float2 c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}
__device__ float2 operator -(float2 a, float2 b)
{
	float2 c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}

__device__ float2 operator *(float a, float2 b)
{
	float2 c;
	c.x = a * b.x;
	c.y = a * b.y;
	return c;
}

__device__ float length(float2 a)
{
	float c = sqrtf(a.x * a.x + a.y * a.y);
	return c;
}


int main()
{
	BzrCrv* Crvs = new BzrCrv[NUM_CRVS];

	//베지에 커브의 CP[3]에 임이의 점을 넣어준다.
	float2 last = { 0, 0 };
	for (int i = 0; i < NUM_CRVS; ++i)
	{
		Crvs[i].CP[0] = last;
		for (int j = 1; j < 3; ++j)
		{
			Crvs[i].CP[j].x = (float)rand() / (float)RAND_MAX; // 0.0 ~ 1.0 사이의 임의 x 좌표
			Crvs[i].CP[j].y = (float)rand() / (float)RAND_MAX; // 0.0 ~ 1.0 사이의 임의 y 좌표
		}
		last = Crvs[i].CP[2]; //n번째 베지에 곡선의 끝점 = n+1번째 베지에 곡선의 시작점
	}


	BzrCrv* Dev_Crvs;	// 전역 메모리 주소
	cudaSetDevice(0);
	cudaMalloc((void**)&Dev_Crvs, sizeof(BzrCrv) * NUM_CRVS);
	cudaMemcpy(Dev_Crvs, Crvs, sizeof(BzrCrv) * NUM_CRVS, cudaMemcpyHostToDevice);
	
	// 커널 함수 호출......
	clock_t st = clock();
	computerBzrCrvs_Parent << <NUM_CRVS / NUM_THREADS, NUM_THREADS >> > (Dev_Crvs, NUM_CRVS); //이전 것은 블록 하나가 곡선 하나를 담당했는데 지금 것은 쓰레드하나가 곡선 하나를 담당
	cudaDeviceSynchronize();
	cudaMemcpy(Crvs, Dev_Crvs, sizeof(BzrCrv) * NUM_CRVS, cudaMemcpyDeviceToHost); //이부분이 문제 왜냐하면 BzrCrv의 float2*는 동적할당 포인터이기 때문에
	clock_t ed = clock();
	printf("Elapsed time = %u ms. \n", ed - st);
	cudaDeviceReset();

	for (int i = 0; i < Crvs[0].nVertices; ++i)
	{
		printf("(x, y) = (%f, %f) \n", Crvs[0].vertexPos[i].x, Crvs[0].vertexPos[i].y);
	}

	// 동적 할당 해제
	freeVertexMem << <NUM_CRVS / NUM_THREADS, NUM_THREADS >> > (Crvs,NUM_CRVS);
	cudaFree(Dev_Crvs);
	delete[] Crvs;
	return 0;
}


//쓰레드 하나가 곡선 하나를 맡는다.
__global__ void computerBzrCrvs_Parent(BzrCrv* Crvs, int NumCrvs)
{
	int i = blockIdx.x * NUM_THREADS + threadIdx.x;

	Crvs[i].nVertices = MAX_SAMPLES; // 각 곡선에서 256개로 샘플링. (곡률에 따라 달라지면 좋지만 그건 힘드니...)
	cudaMalloc((void**)&Crvs[i].vertexPos, Crvs[i].nVertices * sizeof(float2)); //VertexPos 동적 할당
	computeBzrCrvs_Child << <ceil((float)Crvs[i].nVertices/NUM_THREADS),NUM_THREADS >> > (i, Crvs, Crvs[i].nVertices);


	//for (int j = 0; j < MAX_SAMPLES; j += NUM_THREADS)
	//{
	//	int idx = j + threadIdx.x;  // j = 0 -> idx = 0 ~ 31, j = 32 -> idx = 32 ~ 64, 
	//	if (idx < MAX_SAMPLES)
	//	{
	//		float t = (float)idx / (float)(MAX_SAMPLES - 1);  // 0.0 < t < 1.0
	//		float c0 = (1.0f - t) * (1.0f - t);
	//		float c1 = 2.0 * t * (1.0f - t);
	//		float c2 = t * t;
	//		float2 pos = c0 * Crvs[i].CP[0] + c1 * Crvs[i].CP[1] + c2 * Crvs[i].CP[2];
	//		Crvs[i].vertexPos[idx] = pos;
	//	}
	//}
}

__global__ void computeBzrCrvs_Child(int _i, BzrCrv* Crvs, int _numSamples)
{
		int idx = NUM_THREADS * blockIdx.x + threadIdx.x;  // j = 0 -> idx = 0 ~ 31, j = 32 -> idx = 32 ~ 64, 
		float t = (float)idx / (float)(MAX_SAMPLES - 1);  // 0.0 < t < 1.0
		float c0 = (1.0f - t) * (1.0f - t);
		float c1 = 2.0 * t * (1.0f - t);
		float c2 = t * t;
		float2 pos = c0 * Crvs[_i].CP[0] + c1 * Crvs[_i].CP[1] + c2 * Crvs[_i].CP[2];
		Crvs[_i].vertexPos[idx] = pos;
}

__global__ void freeVertexMem(BzrCrv* Crvs, int numCrvs)
{
	int i = NUM_THREADS * blockIdx.x + threadIdx.x;
	cudaFree(Crvs[i].vertexPos);
}