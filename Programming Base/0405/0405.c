#include <stdio.h>

//학과 멀티미디어공학과
//이름 이동원
//학번 2019113931
int main()
{
	//int iValue = 0;
	//scanf_s("%d", &iValue);
	//for (int i = 1; i < 10; i++)
	//{
	//	int iResult = iValue * i;
	//	printf("%d * %d = %d\n", i, iValue, iResult);
	//}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j <= i)
			{
				printf("ㅇ ");
			}
		}
		printf("\n");
	}
}


