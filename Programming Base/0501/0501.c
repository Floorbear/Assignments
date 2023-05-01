#include <stdio.h>

void Step1()
{
	int iAge = 0;
	int iTime = 0;
	int iFee = 0;
	printf("현재 시간과 나이를 입력하시오 (시간 나이) : ");
	scanf_s("%d %d", &iTime, &iAge);

	if (iTime >= 17)
	{
		iFee = 10000;
	}
	else
	{
		if (iAge <= 12 || iAge >= 65)
		{
			iFee = 25000;
		}
		else
		{
			iFee = 34000;
		}
	}
	printf("요금은 %d원 입니다. \n", iFee);
}

int main()
{
	int iLeft = 0;	//f0
	int iRight = 1;	//f1
	int iSum = 0;	//f i+1
	int iCount = 0;	//몇번째 항
	printf("몇번째 항가지 구할까요? ");
	scanf_s("%d", &iCount);

	for (int i = 0; i < iCount+1; i++)
	{
		printf("%d, ", iLeft);
		iSum = iLeft + iRight;
		iLeft = iRight;
		iRight = iSum;
	}


}

