
#include <stdio.h>

void Step1()
{
	int iInput = 0;
	int iMax = 0;
	printf("0 이상의 홀수 정수를 입력하세요 : ");
	scanf_s("%dd", &iInput);
	if (iInput <= 0)
	{
		printf("음수입력 함 ! \n");
		return;
	}

	if (iInput % 2 == 0)
	{
		printf("짝수입력 함 ! \n");
		return;
	}
	iMax = (int)(iInput / 2);
	int starCount = 0;
	for (int i = iMax; i >= 0; --i)
	{
		int starMax = starCount * 2 + 1;
		starCount++;
		for (int blankIter = 0; blankIter < i; ++blankIter)
		{
			printf(" ");
		}

		for (int starIter = 0; starIter < starMax; ++starIter)
		{
			printf("*");
		}

		for (int blankIter = 0; blankIter < i; ++blankIter)
		{
			printf(" ");
		}
		printf("\n");
	}
}
int main()
{
	int iColMax = 0;
	int iDan = 0;
	int iRawMax = 0;
	int iLeft = 0;
	int iRawStartDan = 1;
	printf("한 줄에 얼마나 표현할거임 ? : ");
	scanf_s("%d", &iColMax);
	printf("몇단까지 표현할거임 ?: ");
	scanf_s("%d", &iDan);
	iLeft = iDan % iColMax;
	if (iLeft == 0)
	{
		iRawMax = iDan / iColMax;
	}
	else
	{
		iRawMax = (int)(iDan / iColMax) + 1;
	}


	for (int iRaw = 0; iRaw < iRawMax; ++iRaw) //row
	{
		iRawStartDan = iColMax * iRaw + 1;
		printf("====================================================== \n");
			for (int j = 1; j <= 9; ++j)
			{
				for (int iCol = 0; iCol < iColMax; ++iCol)
				{
					int iIterDan = iRawStartDan + iCol;
					if (iIterDan > iDan)
					{
						continue;
					}
					int iResult = iIterDan * j;
					printf("%2d x %2d = %2d", iIterDan, j, iResult);
					printf("           ");
				}
				printf("\n");
			}
		printf("====================================================== \n");
	}

}

