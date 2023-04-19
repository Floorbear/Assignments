
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <crt/device_functions.h>
#define Size 1024 * 1024 * 1024
#define NumThreads 512

__global__ void parallel_sum1(float* dev_M, int size);//바로 인접한 인덱스를 더하는 것
__global__ void parallel_sum2(float* dev_M, int size);//멀리있는 녀석 들고와서 더하는 것

int main()
{
	float* M = new float[Size];
	for (int i = 0; i < Size; ++i)
	{
		M[i] = rand() / (float)RAND_MAX;
	}

	cudaSetDevice(0);
	float* dev_M1;
	float* dev_M2;

	cudaMalloc((void**)&dev_M1, sizeof(float) * Size);
	cudaMalloc((void**)&dev_M2, sizeof(float) * Size);
	cudaMemcpy(dev_M1, M, sizeof(float) * Size, cudaMemcpyHostToDevice);
	cudaMemcpy(dev_M2, M, sizeof(float) * Size, cudaMemcpyHostToDevice);
	printf("초기화 완료...\n\n");

	//CPU 순차합
	clock_t st = clock();
	double sum = 0.0;
	for (int i = 0; i < Size; ++i)
	{
		sum += M[i];
	}
	clock_t ed = clock();
	printf("cpu 경과 시간 = %u ms \n", ed - st);
	printf("순차합 = %lf\n", sum);

	//쓰레드 구성 정의
	dim3 grid(Size / NumThreads, 1, 1);
	dim3 block(NumThreads, 1, 1);

	//병렬합 (분기)
	st = clock();
	parallel_sum1 << <grid, block >> > (dev_M1, Size);
	cudaDeviceSynchronize();
	cudaMemcpy(M, dev_M1, grid.x * sizeof(float), cudaMemcpyDeviceToHost);
	sum = 0.0;
	for (int i = 0; i < grid.x; ++i)
	{
		sum += M[i];
	}
	ed = clock();
	printf("GPU 경과 시간 = %u ms\n", ed - st);
	printf("병렬합(분기) = %lf\n",sum);

	//병렬합 (덜)
	st = clock();
	parallel_sum2 << <grid, block >> > (dev_M2, Size);
	cudaDeviceSynchronize();
	cudaMemcpy(M, dev_M2, grid.x * sizeof(float), cudaMemcpyDeviceToHost);
	sum = 0.0;
	for (int i = 0; i < grid.x; ++i)
	{
		sum += M[i];
	}
	ed = clock();
	printf("GPU 경과 시간 = %u ms\n", ed - st);
	printf("병렬합(덜분기) = %lf\n", sum);

	//메모리 해제 
	delete[] M;
	cudaFree(dev_M1);
	cudaFree(dev_M2);
}


__global__ void parallel_sum1(float* dev_M, int size)
{
	__shared__ float partialSum[NumThreads];//공유 메모리의 단위는 블럭! 
	int tid = threadIdx.x;
	int i = blockIdx.x * blockDim.x + tid;
	partialSum[tid] = dev_M[i];
	__syncthreads();

	//병렬 reduction 계산
	for (int s = 1; s < blockDim.x; s *= 2)
	{
		if ((tid % (2 * s)) == 0)
		{
			partialSum[tid] += partialSum[tid + s];
		}
		__syncthreads();
	}


	if (tid == 0)
	{
		dev_M[blockIdx.x] = partialSum[0];
	}
}
__global__ void parallel_sum2(float* dev_M, int size)
{
	__shared__ float partialSum[NumThreads];//공유 메모리의 단위는 블럭! 
	int tid = threadIdx.x;
	int i = blockIdx.x * blockDim.x + tid;
	partialSum[tid] = dev_M[i];
	__syncthreads();

	for (int s = blockDim.x / 2; s > 0; s /= 2)
	{
		if (tid < s)
		{
			partialSum[tid] += partialSum[tid + s];
		}
		__syncthreads();
	}

	if (tid == 0)
	{
		dev_M[blockIdx.x] = partialSum[0];
	}
}