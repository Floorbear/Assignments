#include <stdio.h>

int isEven(int _num)
{
	return !(_num % 2);
}

int getAbs(int _num)
{
	if (_num >= 0)
	{
		return _num;
	}
	else
	{
		return -_num;
	}
}

int getSign(int _num)
{
	if (_num < 0)
	{
		return -1;
	}
	else if (_num == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	int input = 0;
	printf("정수를 입력하시오 : ");
	scanf_s("%d", &input);
	printf("isEven()의 결과 : %d\n", isEven(input));
	printf("getAbs()의 결과 : %d\n", getAbs(input));
	printf("getSign()의 결과 : %d\n", getSign(input));
}


