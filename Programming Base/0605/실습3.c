#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define LEN 64
#define LANG 2
#define WORDS 5
#define KOR 0
#define EN 1
int main()
{
	char input[LEN] = { 0, };


	//3차원
	char dicAll[WORDS][LANG][LEN];

	//2차원
	char dicKOR[WORDS][LEN];
	char dicEN[WORDS][LEN];

	//배열 초기화 
	strcpy_s(dicAll[0][KOR], sizeof(dicAll[0][KOR]), "우리");
	strcpy_s(dicAll[0][EN], sizeof(dicAll[0][EN]), "we");
	strcpy_s(dicKOR[0], sizeof(dicKOR[0]), "우리");
	strcpy_s(dicEN [0], sizeof(dicEN [0]), "we");

	strcpy_s(dicAll[1][KOR], sizeof(dicAll[1][KOR]), "좋아하다");
	strcpy_s(dicAll[1][EN],  sizeof(dicAll[1][EN]), "like");
	strcpy_s(dicKOR[1], sizeof(dicKOR[1]), "좋아하다");
	strcpy_s(dicEN [1], sizeof(dicEN [1]), "like");

	strcpy_s(dicAll[2][KOR], sizeof(dicAll[2][KOR]), "프로그램");
	strcpy_s(dicAll[2][EN],  sizeof(dicAll[2][EN]), "program");
	strcpy_s(dicKOR[2], sizeof(dicKOR[2]), "프로그램");
	strcpy_s(dicEN [2], sizeof(dicEN [2]), "program");

	strcpy_s(dicAll[3][KOR], sizeof(dicAll[3][KOR]), "나");
	strcpy_s(dicAll[3][EN],  sizeof(dicAll[3][EN]), "i");
	strcpy_s(dicKOR[3], sizeof(dicKOR[3]), "나");
	strcpy_s(dicEN [3], sizeof(dicEN [3]), "i");

	strcpy_s(dicAll[4][KOR], sizeof(dicAll[4][KOR]), "즐기다");
	strcpy_s(dicAll[4][EN],  sizeof(dicAll[4][EN]), "enjoy");
	strcpy_s(dicKOR[4], sizeof(dicKOR[4]), "즐기다");
	strcpy_s( dicEN[4], sizeof( dicEN[4]), "enjoy");

	int isDicAllMode = 0;
	printf("종료하려면 quit를 입력하십시오.... \n");

	do
	{
		printf("영어를 입력하세요. \n");
		gets_s(input, sizeof(input));
		//문자열 검색
		int wordsIndex = 0;
		for (; wordsIndex < WORDS; wordsIndex++)
		{
			if (isDicAllMode) //3차원 배열 모드
			{
				if (strcmp(dicAll[wordsIndex][EN], input) == 0)
				{
					break;
				}
			}
			else //2차원 배열 모드
			{
				if (strcmp(dicEN[wordsIndex], input) == 0)
				{
					break;
				}
			}

		}

		if (wordsIndex < WORDS)
		{
			if (isDicAllMode) //3차원
			{
				puts(dicAll[wordsIndex][KOR]);
			}
			else //2차원
			{
				puts(dicKOR[wordsIndex]);
			}
		}

	} while (strcmp(input, "quit") != 0);

	system("Pause");
	return 0;
}