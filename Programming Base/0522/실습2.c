#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand((unsigned int)time(NULL));

	int iPointX[5];
	int iPointY[5];

	int iCount = 0;
	//정점에 데이터 할당
	while (iCount < 5)
	{
		iPointX[iCount] = rand() * (200 + 1) / (32767 + 1) - 100;//−100 ≤ 𝑥𝑖, 𝑦𝑖 ≤ 100
		iPointY[iCount] = rand() * (200 + 1) / (32767 + 1) - 100;//−100 ≤ 𝑥𝑖, 𝑦𝑖 ≤ 100

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

	//X기준 삽입  소트
	for (int i = 1; i < iCount; i++)
	{
		int prevIndex = i;
		int prevPointX = iPointX[i];
		int prevPointY = iPointY[i];

		for (int j = i-1; j >= 0; j--)
		{
			if (prevPointX < iPointX[j])
			{
				iPointX[j+1] = iPointX[j];
				iPointY[j+1] = iPointY[j];
				prevIndex = j;
			}
			else if (prevPointX == iPointX[j])
			{
				//X가 동일한경우 Y를 기준으로 삽입 소트
				if (prevPointY < iPointY[j])
				{
					iPointX[j + 1] = iPointX[j];
					iPointY[j + 1] = iPointY[j];
					prevIndex = j;
				}
			}
		}
		iPointX[prevIndex] = prevPointX;
		iPointY[prevIndex] = prevPointY;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("Point[%d](%d,%d)\n", i, iPointX[i], iPointY[i]);
	}
	system("PAUSE");
}