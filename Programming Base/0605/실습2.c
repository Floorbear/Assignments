#include <stdio.h>
#include <string.h>
#define SIZE 64
int main()
{

	char* existedID = "programming_c_23-1";
	char* existedPassword = "a0B1c2D3@";
	char ID[SIZE];
	char password[SIZE];



	printf("ID를 입력해주세요 : ");
	gets_s(ID, sizeof(ID));
	printf("Password를 입력해주세요 : ");
	gets_s(password, sizeof(password));

	int a = strcmp(ID, existedID);
	if (strcmp(ID, existedID) == 0 && strcmp(password, existedPassword) == 0 )
	{
		printf("인증에 성공했습니다 !\n");
	}
	else
	{
		printf("인증에 실패했습니다!\n");
	}

	system("Pause");
	return 0;
}