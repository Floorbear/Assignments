#include <stdio.h>

int isMultiple(int _n, int _m)
{
	return !(_n % _m);
}
int main()
{
	int input1 = 0;
	int input2 = 0;
	int isMult = 0;
	printf("첫 번째 정수를 입력하시오 : ");
	scanf_s("%d", &input1);
	printf("두 번째 정수를 입력하시오 : ");
	scanf_s("%d", &input2);

	isMult = isMultiple(input1, input2);
	if (isMult)
	{
		printf("%d은 %d의 배수입니다. \n ", input2, input1);
	}
	else
	{
		printf("%d은 %d의 배수가 아닙니다. \n ", input2, input1);
	}

}

