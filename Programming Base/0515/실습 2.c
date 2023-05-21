#include <stdio.h>

int checkAlpha(char _char)
{
	return (_char >= 'a' && _char <= 'z') ? 1 : 0;

}

int main()
{
	char input = 0;
	int isAlpha = 0;
	printf("문자를 입력하십시오 : ");
	scanf_s("%c", &input);

	isAlpha = checkAlpha(input);
	if (isAlpha)
	{
		printf("%c는 알파벳 문자입니다. \n", input);
	}
	else
	{
		printf("%c는 알파벳 문자가 아닙니다. \n", input);
	}


}

