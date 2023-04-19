#include <stdio.h>
#include <stdlib.h>
void Step1()
{
    int iInput0 = 0;
    int iInput1 = 0;
    int iInput2 = 0;
    int iResult = 0;

    int iCount = 0;
    while (iCount < 3)
    {
        if (iCount == 0)
        {
            printf("숫자를 입력하시오 : ");
            scanf_s("%d", &iInput0);
            if (iInput0 < 0)
            {
                continue;
            }
            iCount++;
        }
        else if (iCount == 1)
        {
            printf("숫자를 입력하시오 : ");
            scanf_s("%d", &iInput1);
            if (iInput1 < 0)
            {
                continue;
            }
            iCount++;
        }
        else
        {
            printf("숫자를 입력하시오 : ");
            scanf_s("%d", &iInput2);
            if (iInput2 < 0)
            {
                continue;
            }
            iCount++;
        }

    }
    iResult = iInput0 + iInput1 + iInput2;
    printf("합계는 %d입니다. \n", iResult);
}

void Step2()
{
    //셤문제
    int iCurrentFuel = 100;
    int iInput = -1;
    while (iInput != 0)
    {
        printf("현재 연료량 : %d\n", iCurrentFuel);
        if (iCurrentFuel < 20)
        {
            printf("(경고) 연료가 20리터 미만입니다. \n");
        }
        printf("연료 충전은 +, 소모는 -로 입력해주세요 :");
        scanf_s("%d", &iInput);

        iCurrentFuel += iInput;
        if (iCurrentFuel >= 500)
        {
            iCurrentFuel = 500;
        }
        if (iCurrentFuel < 0)
        {
            iCurrentFuel = 0;
        }
    }
}

void Step3()
{
    char iInput;
    int iLeft = 0;
    int iRight = 0;
    int iResult = 0;
    while (1)
    {
        printf("********************\n");
        printf("\n");
        printf("A---- Add       \n");
        printf("S---- Subtract  \n");
        printf("M---- Multiply  \n");
        printf("D---- Divide    \n");
        printf("Q---- Quit      \n");
        printf("\n");
        printf("********************\n");
        scanf("%c ", &iInput);

        if (iInput != 'Q') // 입력처리
        {
            printf("두 수를 공백을 분리하여 입력하시오 : ");
            scanf_s("%d %d", &iLeft, &iRight);
        }

        if (iInput == 'A') //Add
        {
            iResult = iLeft + iRight;
            printf("Result : %d\n", iResult);
        }
        else if (iInput == 'S') //Subtract
        {
            iResult = iLeft - iRight;
            printf("Result : %d\n", iResult);
        }
        else if (iInput == 'M') //Multiply
        {
            iResult = iLeft * iRight;
            printf("Result : %d\n", iResult);
        }
        else if (iInput == 'D') //Divide
        {
            if (iRight == 0)
            {
                printf("에러 : 제로디비전!");
                continue;
            }
            iResult = iLeft / iRight;
            printf("Result : %d\n", iResult);
        }
        else if (iInput == 'Q') //Multiply
        {
            break;
        }
    }
}
int main()
{
    int iAnswer = 0;
    int iQuestion = 0;

    int iUpper = 100;
    int iLower = 0;
    while (1)
    {
        srand(time(NULL));
        iQuestion = rand() % (iUpper - iLower)+ iLower + 1; // 1 ~ 100
        printf("숫자가 %d인가요 ? \n", iQuestion);
        scanf("%d", &iAnswer);
        if (iAnswer == 1) // 높다
        {
            iLower = iQuestion;
        }
        else if (iAnswer == -1) //낮다
        {
            iUpper = iQuestion;
        }
        else if (iAnswer == 0)
        {
            break;
        }

    }
 
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
