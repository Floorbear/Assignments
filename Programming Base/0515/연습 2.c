#include <stdio.h>

int getTax(int _income)
{
	int result = 0;
	if (_income <= 1000)
	{
		result = (int)((float)_income * (8.0 / 100.0));
	}
	else
	{
		result += 80; //1000만원 이하 소득세
		_income -= 1000;
		result += (int)((float)_income * (10.0 / 100.0));
	}
	return result;
}
int main()
{
	int input = 0;
	printf("소득을 입력하시오(만원) : ");
	scanf_s("%d", &input);
	printf("소득세는 %d만원입니다. \n", getTax(input));

}

