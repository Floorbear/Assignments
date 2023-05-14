#include <stdio.h>
#define SIZE 10
#define DATASIZE 2
#define ID 0
#define MONEY 1
int main()
{
	//int iOldID = 115;
	//int iOldMoney = 70;

	int iNewID = -1;
	int iNewMoney = -1;

	//int iID0 = -1;
	//int iMoney0 = -1;

	//int iID1 = -1;
	//int iMoney1 = -1;

	//int iID2 = -1;
	//int iMoney2 = -1;
	int iData[SIZE][DATASIZE]; 


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
			if (iAccountCount >= SIZE)
			{
				printf("**계좌 개설 실패**\n이미 이미 %d개의 계좌가 존재합니다.\n",SIZE);
			}
			else
			{
				int isExist = 0;
				int dataIndex = 0;
				//이미 계좌가 존재하는지 체크
				for (; dataIndex < iAccountCount; dataIndex++)
				{
					if (iNewID == iData[dataIndex][ID])
					{
						isExist = 1;
						break;
					}
				}
				if (isExist)
				{
					printf("**계좌 개설 실패**\n이미 존재하는 아이디입니다.\n");
					iQuickkGo = 1;
				}
				else
				{
					printf("**계좌 개설 성공**\n");
					printf("계좌ID : %d\n", iNewID);
					printf("입금액 : %d\n", iNewMoney);
					iData[iAccountCount][ID] = iNewID;
					iData[iAccountCount][MONEY] = iNewMoney;
					iAccountCount++;
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
				int isExist = 0;
				int dataIndex = 0;
				//이미 계좌가 존재하는지 체크
				for (; dataIndex < iAccountCount; dataIndex++)
				{
					if (iNewID == iData[dataIndex][ID])
					{
						isExist = 1;
						break;
					}
				}
				if (!isExist)
				{
					printf("**입금 실패**\n계좌ID가 존재하지 않습니다.\n");
					iQuickkGo = 1;
				}
				else
				{
					iData[dataIndex][MONEY] += iNewMoney;
					printf("**입금 성공**\n");
					printf("계좌ID : %d\n", iNewID);
					printf("잔액 : %d\n", iData[dataIndex][MONEY]);
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
				int isExist = 0;
				int dataIndex = 0;
				//이미 계좌가 존재하는지 체크
				for (; dataIndex < iAccountCount; dataIndex++)
				{
					if (iNewID == iData[dataIndex][ID])
					{
						isExist = 1;
						break;
					}
				}
				if (!isExist)
				{
					printf("**출금 실패**\n계좌ID가 존재하지 않습니다.\n");
					iQuickkGo = 1;
				}
				else
				{
					if (iNewMoney > iData[dataIndex][MONEY])
					{
						printf("**출금 실패**\n잔액이 부족합니다.\n");
						iQuickkGo = 1;
					}
					else
					{
						iData[dataIndex][MONEY] -= iNewMoney;
						printf("**출금 성공**\n");
						printf("계좌ID : %d\n", iNewID);
						printf("잔액 : %d\n", iData[dataIndex][MONEY]);
					}
				}
			}
			
		}
		else if (iInput == 4)
		{
			for (int i = 0; i < iAccountCount; i++)
			{
				printf("계좌ID : %d\n", iData[i][ID]);
				printf("잔액 : %d\n\n\n", iData[i][MONEY]);
			}
		}
		else if (iInput == 5)
		{
			printf("프로그램을 종료합니다\n");
			return;
		}
	}

}

