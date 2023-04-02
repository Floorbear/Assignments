
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <iostream>
#include <chrono>
#define WIDTH 1001
#define TILE_WIDTH 32

//void Init(float* _P, int _Width, int _Value)
//{
//	for (int i = 0; i < _Width; i++)
//	{
//		_P[i] = rand() % 3 - 1.0;
//	}
//}
void MultMatCPU(float* _P, float* M, float* _N, int _Width)
{
	for (int i = 0; i < _Width; i++)
	{
		for (int j = 0; j < _Width; j++)
		{
			float Sum = 0.0f;
			for (int k = 0; k < _Width; k++)
			{
				//2차원 배열을 1차원 배열로 인덱싱 하는 것 :: !! 이해 잘해 !!
				Sum = Sum + M[i * _Width + k] * _N[k * _Width + j];
			}
			_P[i * _Width + j] = Sum;
		}
	}
}

__global__ void MultMatGPU(float* _P, float* M, float* _N, int _Width) //여기 포인터는 GPU쪽 주소여야 한다.
{
	//!!!!!이미지 좌표처럼 X가 가로, Y가 세로가 된다. i가 행이니 Y, j가 열이니 X가 된다. 헷갈리니 주의하자.!!!!!!!!
	int i = blockIdx.y * TILE_WIDTH +threadIdx.y;
	int j = blockIdx.x * TILE_WIDTH +threadIdx.x;
	float Sum = 0;
	if (i < WIDTH && j < WIDTH) //WIDTH가 TILE_WIDTH의 배수가 아닐 때, 추가로 생성된 블록이 이상한 주소를 참조하는것을 방지하기 위해!!
	{
		for (int k = 0; k < _Width; k++)
		{
			//2차원 배열을 1차원 배열로 인덱싱 하는 것 :: !! 이해 잘해 !! && 내적 파트임
			Sum = Sum + M[i * _Width + k] * _N[k * _Width + j];
		}
		_P[i * _Width + j] = Sum;

	}
}

void PrintMat(float* _P, int _Width)
{
	std::cout << "------------------------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < _Width; i++)
	{
		for (int j = 0; j < _Width; j++)
		{
			printf("%.1f       ", _P[i * _Width + j]);
		}
		std::cout << std::endl;
	}
}
int main()
{
	float* arSum = new float[WIDTH * WIDTH];
	float* arM = new float[WIDTH * WIDTH];
	float* arN = new float[WIDTH * WIDTH];

	for (int i = 0; i < WIDTH * WIDTH; i++)
	{
		arM[i] = rand() % 3 - 1.0;
		arN[i] = rand() % 3 - 1.0;
		arSum[i] = 0;
	}

	cudaSetDevice(0);

	float* devM;
	float* devN;
	float* devP;

	//1. 동적 할당
	cudaMalloc((void**)&devM, WIDTH * WIDTH * sizeof(float));
	cudaMalloc((void**)&devN, WIDTH * WIDTH * sizeof(float));
	cudaMalloc((void**)&devP, WIDTH * WIDTH * sizeof(float));

	//2. CPU 데이터를 GPU에 복사
	cudaMemcpy(devM, arM, WIDTH * WIDTH * sizeof(float), cudaMemcpyHostToDevice);
	cudaMemcpy(devN, arN, WIDTH * WIDTH * sizeof(float), cudaMemcpyHostToDevice);
	cudaMemcpy(devP, arSum, WIDTH * WIDTH * sizeof(float), cudaMemcpyHostToDevice);

	//3. 커널 함수 수행
	dim3 gridDim((WIDTH - 1) / TILE_WIDTH + 1, (WIDTH - 1 ) / TILE_WIDTH + 1, 1);
	dim3 blockDim(TILE_WIDTH, TILE_WIDTH);
	std::chrono::system_clock::time_point St = std::chrono::system_clock::now();
	MultMatGPU << <gridDim,blockDim >> > (devP, devM, devN, WIDTH);
	//MultMatCPU(arSum, arM, arN, INDEX);
	cudaError_t Status = cudaDeviceSynchronize();
	if (Status != cudaSuccess)
	{
		printf("Error");
	}
	cudaMemcpy(arSum, devP, WIDTH * WIDTH * sizeof(float), cudaMemcpyDeviceToHost);

	std::chrono::system_clock::time_point Ed = std::chrono::system_clock::now();

	std::chrono::nanoseconds Time = Ed - St;
	std::chrono::microseconds microTime = std::chrono::duration_cast<std::chrono::microseconds>((Ed - St));
	std::chrono::milliseconds milliTime = std::chrono::duration_cast<std::chrono::milliseconds>((Ed - St));
	PrintMat(arSum, WIDTH);

	//printf("Elapsed Time = %lld nanoseconds \n \n", Time.count());
	printf("Elapsed Time = %lld microseconds \n \n", microTime.count());
	//printf("Elapsed Time = %lld milliseconds \n \n", milliTime.count());



	delete[] arSum;
	delete[] arM;
	delete[] arN;
	cudaFree(devM);
	cudaFree(devN);
	cudaFree(devP);

}

