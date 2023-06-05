
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1024 * 1024 * 1024

void main()
{

	//0 ~ 255 값으로 초기화된 버퍼 배열 생성
	unsigned char* pBuffer = new unsigned char[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		pBuffer[i] = rand() % 256;
	}

	// 히스토그램 계산
	unsigned int Histogram[256] = { 0, };
	printf("Start.... \n");
	clock_t st = clock();
	for (int i = 0; i < SIZE; ++i)
	{
		Histogram[pBuffer[i]]++;
	}
	clock_t ed = clock();
	printf("Elaspsed Time = %u ms \n", ed - st);

	int sum = 0;
	for (int i = 0; i < 256; ++i)
	{
		sum = sum + Histogram[i];
	}
	printf("Sum = %d \n", sum);
	delete[] pBuffer;
}