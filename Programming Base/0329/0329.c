#include <stdio.h>
void Step1()
{
        int iValue = 0;
    int bIsOdd = 0;

    printf("값을 입력해 주세요 : ");
    scanf_s("%d", &iValue);

    bIsOdd = iValue % 2;
    if (bIsOdd)
    {
        printf("홀수 !! \n");
    }
    else
    {
        printf("짝수 !! \n");
    }
}

void Step2()
{
    int iValue1 = 0;
    int iValue2 = 0;
    int iResult1 = 0;
    int iResult2 = 0;
    printf("두 개의 정수르 입력해 주세요 : ");

    scanf_s("%d %d", &iValue1, &iValue2);
    if (iValue2 == 0)
    {
        printf("경고 !! 분모가 0 입니다. \n");
        return -1;
    }

    iResult1 = iValue1 / iValue2;
    iResult2 = iValue1 % iValue2;

    printf("몫은 %d고 나머지는 %d 입니다 !!! \n", iResult1, iResult2);

}

void Step3()
{
    int iValue = 0;
    int bIsYear = 0;
    int iTemp = 0;
    printf("값을 입력해 !! : ");
    scanf_s("%d", &iValue);

    iTemp = iValue % 4;
    if (iTemp == 0)
    {
        bIsYear = 1;
        iTemp = iValue % 100;
        if (iTemp == 0)
        {
            bIsYear = 0;
        }

        iTemp = iValue % 400;
        if (iTemp == 0)
        {
            bIsYear = 1;
        }
    }

    if (bIsYear == 1)
    {
        printf("%d년은 윤년입니다 !! \n", iValue);
    }
    else
    {
        printf("%d년은 평년입니다 !! \n", iValue);
    }
}

void Step4()
{
    char cValue = 0;
    printf("문자 하나 입력해! \n");
    scanf_s("%c", &cValue);
    if (cValue >= 'A' && cValue <= 'Z')
    {
        printf("대문자 ! \n");
    }
    else if (cValue >= 'a' && cValue <= 'z')
    {
        printf("소문자 ! \n");
    }
    else if (cValue >= '0' && cValue <= '9')
    {
        printf("숫자 ! \n");
    }
    else
    {
        printf("그외 문자 ! \n");
    }
}

int main()
{
    int iLeftValue = 0;
    int iRightValue = 0;
    int iResult = 0;
    char cOperator = 0;

    printf("식을 입력해 주세요 : ");
    scanf("%d %c %d", &iLeftValue, &cOperator, &iRightValue);


    switch (cOperator)
    {
    case '+':
        iResult = iLeftValue + iLeftValue;
        break;
    case '-':
        iResult = iLeftValue - iLeftValue;
        break;
    case '*':
        iResult = iLeftValue * iLeftValue;
        break;
    case '/':
        iResult = iLeftValue / iLeftValue;
        break;
    case '%':
        iResult = iLeftValue % iLeftValue;
        break;
    default:
        break;
    }

    printf("결과는 %d 입니다!@", iResult);
    


}

