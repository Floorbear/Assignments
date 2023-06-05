#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#define SIZE 64
int main()
{
	char c = 0;
	char inputArr[SIZE];
	int len = 0;
	int lower = 0;
	int upper = 0;
	int number = 0;
	
	c = getchar();
	while (!isspace(c))
	{
		if (isupper(c))
		{
			upper++;
		}

		if (islower(c))
		{
			lower++;
		}

		if (isdigit(c))
		{
			number++;
		}

		len++;
		c = getchar();
	}

	if (len < 7 || !lower || !number || !upper)
	{
		printf("유효하지 않은 암호입니다. \n");
	}
	else
	{
		printf("유효한 암호입니다. \n");
	}

	system("Pause");
	return 0;
}