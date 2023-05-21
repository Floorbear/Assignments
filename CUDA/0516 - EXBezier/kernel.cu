
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <cuda.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_CRVS	1024 * 1024		// 블록의 수 = 만들려는 베지에 곡선의 수 
#define	NUM_THREADS	32
#define MAX_SAMPLES 256

// 2차 베지에 곡선을 표현하는 구조체
struct BzrCrv {
	float2 CP[3];	// 제어점 3개 배열
	int nVertices;	// 곡선 위의 샘플링 점의 수 (4 ~ 256)
	float2 vertexPos[MAX_SAMPLES];	// 곡선 위의 샘플링된 점의 좌표
};

//하나의 베지에 곡선은 3개의 정점을 필요로 한다.
//NUM_CRVS 만큼의 베지에 곡선을 동적생성한다.
//생성된 베지에 곡선마다 정점을 넣어준다.
//생성된 베지에 곡선을 매게변수로 커널함수를 돌린다.
// 
//한 블록은 하나의 베지에 곡선을 정의한다.
//한 블록당 베지에 샘플링(베지에 곡선의 정점 수)은 256개다.
//한 블록당 쓰레드는 32개다
//쓰레드 하나당 베지에 정점 8개를 정의 해야한다.

__global__ void computerBzrCrvs(BzrCrv* Crvs, int NumCrvs);

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
	computerBzrCrvs << <NUM_CRVS, NUM_THREADS >> > (Dev_Crvs, NUM_CRVS);
	cudaMemcpy(Crvs, Dev_Crvs, sizeof(BzrCrv) * NUM_CRVS, cudaMemcpyDeviceToHost);
	clock_t ed = clock();
	printf("Elapsed time = %u ms. \n", ed - st);
	cudaDeviceReset();

	for (int i = 0; i < Crvs[0].nVertices; ++i)
	{
		printf("(x, y) = (%f, %f) \n", Crvs[0].vertexPos[i].x, Crvs[0].vertexPos[i].y);
	}

	// 동적 할당 해제
	cudaFree(Dev_Crvs);
	delete[] Crvs;
	return 0;
}


//각 블록은 하나의 베지에 곡선을 정의한다.
//한 블록당 베지에 샘플링은 256개다.
//한 블록당 쓰레드는 32개다
//쓰레드 하나당 베지에 정점 8개를 정의 해야한다.
__global__ void computerBzrCrvs(BzrCrv* Crvs, int NumCrvs)
{
	int i = blockIdx.x;
	if (i < NumCrvs)
	{
		Crvs[i].nVertices = MAX_SAMPLES; // 각 곡선에서 256개로 샘플링.

		for (int j = 0; j < MAX_SAMPLES; j += NUM_THREADS)
		{
			int idx = j + threadIdx.x;  // j = 0 -> idx = 0 ~ 31, j = 32 -> idx = 32 ~ 64, 
			if (idx < MAX_SAMPLES)
			{
				float t = (float)idx / (float)(MAX_SAMPLES - 1);  // 0.0 < t < 1.0
				float c0 = (1.0f - t) * (1.0f - t);
				float c1 = 2.0 * t * (1.0f - t);
				float c2 = t * t;
				float2 pos = c0 * Crvs[i].CP[0] + c1 * Crvs[i].CP[1] + c2 * Crvs[i].CP[2];
				Crvs[i].vertexPos[idx] = pos;
			}
		}
	}
}

