
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1024 * 1024 *1024
#define NUMTHREAD 256

__global__ void Histo_kernel(unsigned int* _histogram, unsigned char* _buffer, int _size)
{
	__shared__ unsigned int tmp_histo[256];
	tmp_histo[threadIdx.x] = 0;
	__syncthreads();

	int bx = blockIdx.x;
	int tx = threadIdx.x;
	int i = bx * blockDim.x + tx;

	atomicAdd(&tmp_histo[_buffer[i]], 1);
	//_histogram[_buffer[i]]++;
	__syncthreads();

	atomicAdd(&_histogram[tx], tmp_histo[tx]);

}

int main()
{
	//0 ~ 255 값으로 초기화된 버퍼 배열 생성
	unsigned char* pBuffer = new unsigned char[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		pBuffer[i] = rand() % 256;
	}
	unsigned int Histogram[256] = { 0, };


	//사용할 GPU 선택하고, 메모리 할당
	cudaSetDevice(0);
	unsigned char* dev_buffer = nullptr;
	cudaMalloc((void**)&dev_buffer, sizeof(unsigned char) * SIZE);
	cudaMemcpy(dev_buffer, pBuffer, sizeof(unsigned char) * SIZE, cudaMemcpyHostToDevice);

	unsigned int* dev_histogram = nullptr;
	cudaMalloc((void**)&dev_histogram, sizeof(unsigned int) * 256);
	cudaMemset(dev_histogram, 0, sizeof(unsigned int) * 256); // 값을 0으로 초기화

	printf("Start.... \n");
	clock_t st = clock();
	Histo_kernel<<<SIZE / NUMTHREAD,NUMTHREAD>>>(dev_histogram, dev_buffer, SIZE);
	cudaDeviceSynchronize();
	clock_t ed = clock();
	cudaMemcpy(Histogram, dev_histogram, sizeof(unsigned int) * 256, cudaMemcpyDeviceToHost);
	printf("Elapsed Time : %u ms\n", ed - st);

	//결과 검증
	int sum = 0;
	for (int i = 0; i < 256; ++i)
	{
		sum = sum + Histogram[i];
	}
	printf("Sum = %d \n", sum);
	delete[] pBuffer;
	cudaFree(dev_buffer);
	cudaFree(dev_histogram);
}