#include <stdio.h>

int main()
{
	//int iOldID = 115;
	//int iOldMoney = 70;

	int iNewID = -1;
	int iNewMoney = -1;

	int iID0 = -1;
	int iMoney0 = -1;

	int iID1 = -1;
	int iMoney1 = -1;

	int iID2 = -1;
	int iMoney2 = -1;

	int iAccountCount = 0;

	int iInput = 0;

	int iQuickkGo = 0;

	while (1)
	{
		if (iQuickkGo == 0)
		{
			printf("---- Menu ---- \n");
			printf("1.	계좌 개설 \n");
			printf("2.	입금 \n");
			printf("3.	출금 \n");
			printf("4.	계좌정보 전체 출력 \n");
			printf("5.	프로그램 종료 \n");
			printf("선택 : ");
			scanf_s("%d", &iInput);
		}
		else //오류 발생하면 빠르게 이전 창으로 이동하기 위해
		{
			iQuickkGo = 0;
		}

		if (iInput == 1)
		{
			printf("[계좌개설]\n");
			printf("계좌ID : ");
			scanf_s("%d", &iNewID);
			printf("입금액 : ");
			scanf_s("%d", &iNewMoney);
			if (iAccountCount >= 3)
			{
				printf("**계좌 개설 실패**\n이미 이미 3개의 계좌가 존재합니다.\n");
			}
			else
			{
				if (iNewID == iID0)
				{
					printf("**계좌 개설 실패**\n이미 존재하는 아이디입니다.\n");
					iQuickkGo = 1;

				}
				else if (iNewID == iID1)
				{
					printf("**계좌 개설 실패**\n이미 존재하는 아이디입니다.\n");
					iQuickkGo = 1;
				}
				else if (iNewID == iID2)
				{
					printf("**계좌 개설 실패**\n이미 존재하는 아이디입니다.\n");
					iQuickkGo = 1;
				}
				else
				{
					iAccountCount++;
					printf("**계좌 개설 성공**\n");
					printf("계좌ID : %d\n", iNewID);
					printf("입금액 : %d\n", iNewMoney);
					if (iID0 == -1) // -1 : 아직 계좌가 만들어지지 않음
					{
						iID0 = iNewID;
						iMoney0 = iNewMoney;
					}
					else if (iID1 == -1)
					{
						iID1 = iNewID;
						iMoney1 = iNewMoney;
					}
					else
					{
						iID2 = iNewID;
						iMoney2 = iNewMoney;
					}
				}
			}

		}
		else if (iInput == 2)
		{
			printf("[입 금]\n");
			printf("계좌ID : ");
			scanf_s("%d", &iNewID);
			printf("입금액 : ");
			scanf_s("%d", &iNewMoney);
			if (iAccountCount == 0)
			{
				printf("**입금 실패**\n현재 프로그램에 개설된 계좌가 하나도 존재하지 않습니다\n");
			}
			else
			{
				if (iID0 != iNewID && iID1 != iNewID && iID2 != iNewID) //계좌가 아예 존재하지 않을 수 있으니 메뉴로 돌아가야한다.
				{
					printf("**입금 실패**\n계좌ID가 존재하지 않습니다.\n");
					iQuickkGo = 1;
				}
				else
				{
					if (iID0 == iNewID)
					{
						iMoney0 += iNewMoney;
						printf("**입금 성공**\n");
						printf("계좌ID : %d\n", iNewID);
						printf("잔액 : %d\n", iMoney0);
					}
					else if (iID1 == iNewID)
					{
						iMoney1 += iNewMoney;
						printf("**입금 성공**\n");
						printf("계좌ID : %d\n", iNewID);
						printf("잔액 : %d\n", iMoney1);
					}
					else
					{
						iMoney2 += iNewMoney;
						printf("**입금 성공**\n");
						printf("계좌ID : %d\n", iNewID);
						printf("잔액 : %d\n", iMoney2);
					}
				}
			}
			
		}
		else if (iInput == 3)
		{
			printf("[출 금]\n");
			printf("계좌ID : ");
			scanf_s("%d", &iNewID);
			printf("출금액 : ");
			scanf_s("%d", &iNewMoney);
			if (iAccountCount == 0)
			{
				printf("**출금 실패**\n현재 프로그램에 개설된 계좌가 하나도 존재하지 않습니다\n");
			}
			else
			{
				if (iID0 != iNewID && iID1 != iNewID && iID2 != iNewID)
				{
					printf("**출금 실패**\n계좌ID가 존재하지 않습니다.\n");
					iQuickkGo = 1;
				}
				else
				{
					if (iID0 == iNewID)
					{
						if (iNewMoney > iMoney0)
						{
							printf("**출금 실패**\n잔액이 부족합니다.\n");
							iQuickkGo = 1;
						}
						else
						{
							iMoney0 -= iNewMoney;
							printf("**출금 성공**\n");
							printf("계좌ID : %d\n", iNewID);
							printf("잔액 : %d\n", iMoney0);
						}
					}
					else if (iID1 == iNewID)
					{
						if (iNewMoney > iMoney1)
						{
							printf("**출금 실패**\n잔액이 부족합니다.\n");
							iQuickkGo = 1;
						}
						else
						{
							iMoney1 -= iNewMoney;
							printf("**출금 성공**\n");
							printf("계좌ID : %d\n", iNewID);
							printf("잔액 : %d\n", iMoney1);
						}
					}
					else
					{
						if (iNewMoney > iMoney0)
						{
							printf("**출금 실패**\n잔액이 부족합니다.\n");
							iQuickkGo = 1;
						}
						else
						{
							iMoney2 -= iNewMoney;
							printf("**출금 성공**\n");
							printf("계좌ID : %d\n", iNewID);
							printf("잔액 : %d\n", iMoney2);
						}
					}
				}
			}
			
		}
		else if (iInput == 4)
		{
			if (iID0 != -1)
			{
				printf("계좌ID : %d\n", iID0);
				printf("잔액 : %d\n\n\n", iMoney0);
			}

			if (iID1 != -1)
			{
				printf("계좌ID : %d\n", iID1);
				printf("잔액 : %d\n\n\n", iMoney1);
			}

			if (iID2 != -1)
			{
				printf("계좌ID : %d\n", iID2);
				printf("잔액 : %d\n\n\n", iMoney2);
			}
	
		}
		else if (iInput == 5)
		{
			printf("프로그램을 종료합니다\n");
			return;
		}
	}

}

