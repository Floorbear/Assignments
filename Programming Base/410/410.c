#include <stdio.h>

void Step1()
{
	//최대공약수
	int iValue1 = 0;
	int iValue2 = 0;
	int iResult = 0;
	int iSmaller = 0;
	int iBigger = 0;
	printf("두 정수를 입력해 주세요 : ");
	scanf_s("%d %d", &iValue1, &iValue2);

	//두 정수의 대소비교
	if (iValue1 < iValue2)
	{
		iSmaller = iValue1;
		iBigger = iValue2;
	}
	else
	{
		iSmaller = iValue2;
		iBigger = iValue1;
	}

	//index로 iBigger을 나눠서 나눠떨어지면 최대공약수로 저장 & 덮어쓰기
	for (int i = 1; i <= iSmaller; i++)
	{
		int iRemain = iSmaller % i;
		if (iRemain == 0)
		{
			int iRemain = iBigger % i;
			if (iRemain == 0)
			{
				iResult = i;
			}
		}
	}

	printf("최대 공약수는 %d입니다. \n", iResult);
}

void Step2()
{
	int iValue = 0;
	printf("정수를 입력해 주세요 : ");
	scanf_s("%d", &iValue);

	for (int i = 0; i < iValue; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%d ", j + 1);
		}
		printf("\n");
	}
}

//실습1
void Step3()
{
	for (int i = 6; i >= 0; i--)
	{
		for (int j = 0; j < 7; j++)
		{
			if (j < i)
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}

}

int main()
{


}


