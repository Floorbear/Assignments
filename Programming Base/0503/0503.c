#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void Step1()
{
	int iCount[SIZE];
	int iMin = 1000000;
	int iMax = -1000000;
	for (int i = 0; i < SIZE; i++)
	{
		int iInput = 0;
		printf("[%02d] 번째 정수 입력 : ", i + 1);
		scanf_s("%d", &iInput);
		if (iInput < iMin)
		{
			iMin = iInput;
		}
		if (iInput > iMax)
		{
			iMax = iInput;
		}
		iCount[i] = iInput;
	}
	printf("\n=============== 입력된 값 =============\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("[%02d]   ", iCount[i]); 
	}
	printf("\n");
	printf("입력된 값 중에서 최소값 [%02d]\n", iMin);
	printf("입력된 값 중에서 최대값 [%02d]\n", iMax);
}
int main()
{
	int iResult[6] = { 0,0,0,0,0,0 };
	int iCount = 0;
	while (iCount < 6)
	{
		srand(time(0));
		int iRandomNo = (rand() % 45) + 1;
		int isExistSame = 0;
		for (int i = 0; i < iCount; i++)
		{
			if (iResult[i] == iRandomNo)
			{
				isExistSame = 1;
				break;
			}
		}
		if (isExistSame)
		{
			continue;
		}
		iResult[iCount] = iRandomNo;
		iCount++;
	}
	for (int i = 0; i < iCount; i++)
	{
		printf("%d \n", iResult[i]);
	}


}

