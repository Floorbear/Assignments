#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define TRUE 1
//이동원
//멀미공
//2019113631

void Step1()
{
	int iValue = 0;
	scanf_s("%d", &iValue);

	int iInput = 0;
	do
	{
		scanf_s("%d", &iInput);
		iValue += iInput;
	} while (iInput != 0);

	printf("총 더한 값 : %d \n", iValue);
}

void Step2()
{

	srand(2019113632);
	int iRandomValue = rand() % 100 + 1;
	int iLeft = 1;
	int iRight = 100;
	while (TRUE)
	{

		int iInput = rand() % 50;
		printf("%d ~ %d 정수를 입력하시오 : ", iLeft, iRight);
		scanf_s("%d", &iInput);

		if (iInput == iRandomValue)
		{
			break;
		}
		else if (iInput < iRandomValue)
		{
			iLeft = iInput;
		}
		else
		{
			iRight = iInput;
		}

	}
	printf("맞습니다. 컴퓨터가 생성한 수는 [%d]입니다.", iRandomValue);
}

void Step2_Ex()
{
	srand(2019113632);
	int iRandomValue = rand() % 100 + 1;
	int iLeft = 1;
	int iRight = 100;
	while (TRUE)
	{
		srand(time(NULL));
		int iInput = rand() % (iRight - iLeft) + iLeft;
		Sleep(1000);
		printf("%d ~ %d 정수를 입력하시오 : %d \n", iLeft, iRight, iInput);

		if (iInput == iRandomValue)
		{
			break;
		}
		else if (iInput < iRandomValue)
		{
			iLeft = iInput;
		}
		else
		{
			iRight = iInput;
		}

	}
	printf("맞습니다. 컴퓨터가 생성한 수는 [%d]입니다.", iRandomValue);
}


int main()
{
	char iInput;
	do
	{
		printf("소문자를 입력해주세요   :    ");
		scanf_s("%c", &iInput);

		if (iInput > 'a' && iInput < 'z')
		{
			printf("%c -> %c", iInput, iInput - 32);
			break;
		}

	} while (TRUE);

}

