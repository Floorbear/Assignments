#include <stdio.h>

float vectorDotProd(float _a[3], float _b[3])
{
	float Result = _a[0] * _b[0];
	Result += _a[1] * _b[1];
	Result += _a[2] * _b[2];
	return Result;
}

int main()
{
	float vectorA[3] = { 0, };
	float vectorB[3] = { 0, };
	float dotResult = 0;

	printf("3차원 벡터 X를 x,y,z,순으로 입력하시오.");
	scanf_s("%f %f %f", &vectorA[0], &vectorA[1], &vectorA[2]);
	printf("3차원 벡터 Y를 x,y,z,순으로 입력하시오.");
	scanf_s("%f %f %f", &vectorB[0], &vectorB[1], &vectorB[2]);
	dotResult = vectorDotProd(vectorA, vectorB);
	printf("[%.2f %.2f %.2f] * [%.2f %.2f %.2f] = %.2f\n", vectorA[0], vectorA[1], vectorA[2],
		vectorB[0], vectorB[1], vectorB[2], dotResult);

	system("PAUSE");


}