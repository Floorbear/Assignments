
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cublas_v2.h>

#define IDX2C(i,j,ld)	((j)*(ld) +(i))

void main()
{
	//CPU 메모리 할당
	int M = 2, K = 3, N = 2;
	float* A = new float[M * K];
	float* B = new float[K * N];
	float* C = new float[M * N];

	//A행렬 초기화
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < K; ++j)
			A[IDX2C(i, j, M)] = rand() % 10;
	}

	//B행렬 초기화
	for (int i = 0; i < K; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			B[IDX2C(i, j, K)] = rand() % 10;
		}
	}

	//GPU 메모리 할당
	float* dev_A = nullptr;
	float* dev_B = nullptr;
	float* dev_C = nullptr;

	cudaMalloc((void**)&dev_A, M * K * sizeof(float));
	cudaMalloc((void**)&dev_B, K * N * sizeof(float));
	cudaMalloc((void**)&dev_C, M * N * sizeof(float));
	cudaMemset(dev_C, 0, M * N * sizeof(float));

	//cublas 핸들 생성
	cublasHandle_t handle;
	cublasCreate(&handle);

	//CPU 데이터를 GPU로 복사
	cublasSetMatrix(M, K, sizeof(float), A, M, dev_A, M);
	cublasSetMatrix(K, N, sizeof(float), B, K, dev_B, K);

	//3단계 cublas 함수 호출 (alpha * A * B + beta * C)
	const float alpha = 1.0, beta = 0.0;
	cublasSgemm(handle, CUBLAS_OP_N, CUBLAS_OP_N,
		M, N, K,
		&alpha, dev_A, M,
		dev_B, K,
		&beta, dev_C, M);

	// GPU -> CPU로 결과 복사 
	cublasGetMatrix(M, N, sizeof(float), dev_C, M, C, M);

	//핸들 제거
	cublasDestroy(handle);

	//행렬 A 출력
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			printf("%5.0f ", A[IDX2C(i, j, M)]);
		}
		printf("\n");
	}

	printf("\n");

	//행렬 B 출력
	for (int i = 0; i <K; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%5.0f ", B[IDX2C(i, j, K)]);
		}
		printf("\n");
	}

	printf("\n");

	//행렬 C 출력
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%5.0f ", C[IDX2C(i, j, M)]);
		}
		printf("\n");
	}

	delete[] A;
	delete[] B;
	delete[] C;
	cudaFree(dev_A);
	cudaFree(dev_B);
	cudaFree(dev_C);

}

