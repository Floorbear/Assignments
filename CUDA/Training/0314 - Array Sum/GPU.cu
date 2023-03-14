
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

# define INDEXCOUNT 1024

void AddCPU(float* _Des, float* _Target1, float* _Target2, int _IndexCount)
{
    for (int i = 0; i < _IndexCount; i++)
    {
        _Des[i] = _Target1[i] + _Target2[i];
    }
}

__global__ void AddGPU(float* _Des, float* _Target1, float* _Target2)
{
    int Block = blockIdx.x;
    int i = Block * 1024 + threadIdx.x;
    _Des[i] = _Target1[i] + _Target2[i];
}

void PrintArray(float* _Array, int _IndexCount)
{
    for (int i = 0; i < _IndexCount; i++)
    {
        printf("%.5f   ", _Array[i]);
    }
    printf("\n");
}

int main()
{
    cudaError_t Status = cudaSetDevice(0);

    assert(Status == cudaSuccess);

    float* Arr1 = new float[INDEXCOUNT];
    float* Arr2 = new float[INDEXCOUNT];
    float* ArrSum = new float[INDEXCOUNT];

    for (int i = 0; i < INDEXCOUNT; i++)
    {
        Arr1[i] = rand() / static_cast<float>(RAND_MAX);
        Arr2[i] = -Arr1[i];
        ArrSum[i] = -1.f;
    }


    float* GPU_Arr1;
    float* GPU_Arr2;
    float* GPU_ArrSum;

    //메모리 할당
    Status = cudaMalloc((void**)&GPU_Arr1, INDEXCOUNT * sizeof(float));
    Status = cudaMalloc((void**)&GPU_Arr2, INDEXCOUNT * sizeof(float));
    Status = cudaMalloc((void**)&GPU_ArrSum, INDEXCOUNT * sizeof(float));

    //GPU에 메모리 복사
    Status = cudaMemcpy(GPU_Arr1, Arr1, INDEXCOUNT * sizeof(float), cudaMemcpyHostToDevice);
    Status = cudaMemcpy(GPU_Arr2, Arr2, INDEXCOUNT * sizeof(float), cudaMemcpyHostToDevice);
    Status = cudaMemcpy(GPU_ArrSum, ArrSum, INDEXCOUNT * sizeof(float), cudaMemcpyHostToDevice);


    //PrintArray(Arr1, INDEXCOUNT);
    //PrintArray(Arr2, INDEXCOUNT);
    clock_t cStart = clock();
    //AddCPU(ArrSum, Arr1, Arr2, INDEXCOUNT);
    //!! 중요 !!
    //! 한 블록 당 쓰레드의 최대 개수가 존재한다 (대략 1024개 이상)
    //! 따라서 쓰레드 수가 많아질 것같으면 블록을 추가해야 한다.
    //! 몇번째 블록인지  blockIdx를 통해 확인 가능하다
    AddGPU<<<INDEXCOUNT / 1024,1024>>>(GPU_ArrSum, GPU_Arr1, GPU_Arr2);
    Status = cudaDeviceSynchronize();
    clock_t cEnd = clock();


    Status = cudaMemcpy(ArrSum, GPU_ArrSum, INDEXCOUNT * sizeof(float), cudaMemcpyDeviceToHost);
    PrintArray(ArrSum, INDEXCOUNT);
    // PrintArray(ArrSum, INDEXCOUNT);

    printf("경과 시간 : %u (ms)", cEnd - cStart);

    delete[] Arr1;
    delete[] Arr2;
    delete[] ArrSum;
    cudaFree(GPU_Arr1);
    cudaFree(GPU_Arr2);
    cudaFree(GPU_ArrSum);

    return 0;
}

