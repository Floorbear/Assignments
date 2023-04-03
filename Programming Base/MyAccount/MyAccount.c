#include <stdio.h>

int main()
{
	int iOldID = 115;
	int iOldMoney = 70;

	int iNewID = -1;
	int iNewMoney = -1;

	int iInput = 0;

	printf("---- Menu ---- \n");
	printf("1.	계좌 계설 \n");
	printf("2.	입금 \n");
	printf("3.	출금 \n");
	printf("4.	계좌정보 전체 출력 \n");
	printf("5.	프로그램 종료 \n");
	printf("선택 : ");
	scanf_s("%d", &iInput);

	if (iInput == 1)
	{
		printf("[계좌개설]\n");
		printf("계좌ID : ");
		scanf_s("%d", &iNewID);
		printf("입금액 : ");
		scanf_s("%d", &iNewMoney);
		if (iNewID == iOldID)
		{
			printf("**계좌 개설 실패**\n이미 존재하는 아이디입니다.\n");
			return;
		}
		printf("**계좌 개설 성공**\n");
		printf("계좌ID : %d\n",iNewID);
		printf("입금액 : %d\n",iNewMoney);
		return;
	}
	else if (iInput == 2)
	{
		printf("[입 금]\n");
		printf("계좌ID : ");
		scanf_s("%d", &iNewID);
		printf("입금액 : ");
		scanf_s("%d", &iNewMoney);
		if (iOldID != iNewID)
		{
			printf("**입금 실패**\n계좌ID가 존재하지 않습니다.\n");
			return;
		}
		iOldMoney += iNewMoney;
		printf("**입금 성공**\n");
		printf("계좌ID : %d\n", iNewID);
		printf("입금액 : %d\n", iOldMoney);
		return;
	}
	else if (iInput == 3)
	{
		printf("[출 금]\n");
		printf("계좌ID : ");
		scanf_s("%d", &iNewID);
		printf("출금액 : ");
		scanf_s("%d", &iNewMoney);
		if (iOldID != iNewID)
		{
			printf("**출금 실패**\n계좌ID가 존재하지 않습니다.\n");
			return;
		}
		if (iNewMoney > iOldMoney)
		{
			printf("**출금 실패**\n잔액이 부족합니다.\n");
			return;
		}
		iOldMoney -= iNewMoney;
		printf("**출금 성공**\n");
		printf("계좌ID : %d\n", iNewID);
		printf("출금액 : %d\n", iOldMoney);
		return;
	}
	else if (iInput == 4)
	{
		printf("계좌ID : %d\n", iOldID);
		printf("입금액 : %d\n", iOldMoney);
		return;
	}
	else if (iInput == 5)
	{
		printf("프로그램을 종료합니다\n");
		return;
	}
}

