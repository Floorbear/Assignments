#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Step1()
{
	unsigned int iInput = 1;
	int item[10];
	int iResult = 0;
	for (int i = 0; i < 10; i++)
	{
		item[i] = rand() % 100 + 1;
	}

	printf("상품 번호를 입력해 주세요 : ");
	scanf_s("%d", &iInput);
	iInput = iInput - 1; // 1~10 > 0~9
	iResult = item[iInput];
	iInput = iInput + 1; // 0~9  > 1~10
	printf("상품 %d번은 선반 %d에 있습니다.", iInput, iResult);
}

void Step2()
{
	int iPointX[5];
	int iPointY[5];

	int iCount = 0;
	while (iCount < 5)
	{
		srand((unsigned int)time(NULL));
		iPointX[iCount] = rand() % 200000 - 100000;//−100000 ≤ 𝑥𝑖, 𝑦𝑖 ≤ 100000
		iPointY[iCount] = rand() % 200000 - 100000;//−100000 ≤ 𝑥𝑖, 𝑦𝑖 ≤ 100000

		//중복된 점이 있는지 확인
		int isOverlap = 0;
		for (int i = 0; i < iCount; i++)
		{
			if (iPointX[i] == iPointX[iCount] && iPointY[i] == iPointY[iCount])
			{
				isOverlap = 1;
			}
		}

		//중복이 있으면 정점을 다시 할당 받는다.
		if (isOverlap)
		{
			continue;
		}
		iCount++;
	}

	//X기준 버블 소트
	for (; iCount > 0; iCount--)
	{
		for (int i = 0; i < iCount - 1; i++)
		{
			if (iPointX[i] > iPointX[i + 1])
			{
				int iTempX = iPointX[i + 1];
				int iTempY = iPointY[i + 1];
				iPointX[i + 1] = iPointX[i];
				iPointY[i + 1] = iPointY[i];
				iPointX[i] = iTempX;
				iPointY[i] = iTempY;
			}
			else if (iPointX[i] == iPointX[i + 1])
			{
				//X가 동일한경우 Y를 기준으로 버블소트
				if (iPointY[i] > iPointY[i + 1])
				{
					int iTempX = iPointX[i + 1];
					int iTempY = iPointY[i + 1];
					iPointX[i + 1] = iPointX[i];
					iPointY[i + 1] = iPointY[i];
					iPointX[i] = iTempX;
					iPointY[i] = iTempY;
				}
			}
		}
	}
}


int main()
{
	Step2();
}
