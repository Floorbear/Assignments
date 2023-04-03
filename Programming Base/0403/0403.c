#include <stdio.h>



int main()
{
	int iDiceEyes1 = 0;
	int iDiceEyes2 = 0;
	int iDiceEyes3 = 0;
	int iSameCount = 0;
	int iMostEyes = 0;
	int iSameEyes = 0;
	int iMoney = 0;

	printf("주사위 눈 3개를 입력해 주세요 : \n");
	scanf_s("%d %d %d", &iDiceEyes1, &iDiceEyes2, &iDiceEyes3);

	iMostEyes = iDiceEyes1;
	if (iDiceEyes2 > iMostEyes)
	{
		iMostEyes = iDiceEyes2;
	}
	if (iDiceEyes3 > iMostEyes)
	{
		iMostEyes = iDiceEyes3;
	}

	if (iDiceEyes1 == iDiceEyes2)
	{
		iSameCount = 2;
		iSameEyes = iDiceEyes1;
		if (iDiceEyes1 == iDiceEyes3)
		{
			iSameCount = 3;
		}
	}
	else if (iDiceEyes1 == iDiceEyes3)
	{
		iSameCount = 2;
		iSameEyes = iDiceEyes1;
	}
	else if (iDiceEyes2 == iDiceEyes3)
	{
		iSameCount = 2;
		iSameEyes = iDiceEyes2;
	}

	if (iSameCount == 0)
	{
		iMoney = iMostEyes * 100;
	}
	else if (iSameCount == 2)
	{
		iMoney = 1000 + iSameEyes * 100;
	}
	else if (iSameCount == 3)
	{
		iMoney = 10000 + iSameEyes * 1000;
	}

	printf("상금 : %d", iMoney);
}
