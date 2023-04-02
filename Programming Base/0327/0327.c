#include <stdio.h>
#include <assert.h>

void Step1()
{
    int iValue = 0;
    int iFirst = 0;
    int iLast = 0;
    printf("100보다 작은 변수를 입력해 주세요 \n");
    scanf_s("%d", &iValue);
    iFirst = iValue / 10;
    iLast = iValue % 10;
    printf("십의 자리 : %d \n", iFirst);
    printf("일의 자리 : %d \n", iLast);
}

void Step2()
{
    int iX = 0;
    int iY = 0;
    int iResult = 0;
    printf("x : ");
    scanf_s("%d", &iX);
    printf("y : ");
    scanf_s("%d", &iY);

    iResult = iX > 0 ? (iY > 0 ? 1 : 4) : (iY > 0 ? 2 : 3);
    printf("%d사분면  \n", iResult);
}

void Step3() //실습1
{
    double dTall1 = 0;
    double dTall2 = 0;
    double dTall3 = 0;

    double dMost = 0;
    double dWorst = 0;

    double dIn = 0;
    int iFeet = 0;
    double dInc = 0.;

    printf("키 1을 입력하시오 : ");
    scanf_s("%lf", &dTall1);
    printf("키 2을 입력하시오 : ");
    scanf_s("%lf", &dTall2);
    printf("키 3을 입력하시오 : ");
    scanf_s("%lf", &dTall3);

    dMost = (dTall1 > dTall2 && dTall1 > dTall3) ? dTall1 : (dTall2 > dTall3 ? dTall2 : dTall3);
    dWorst = (dTall1 < dTall2&& dTall1 < dTall3) ? dTall1 : (dTall2 < dTall3 ? dTall2 : dTall3);

    printf("가장 큰 키는 %lf 입니다 \n", dMost);
    printf("가장 작은 키는 %lf 입니다 \n", dWorst);

    dIn = dTall1 / 2.54;
    iFeet = (int)(dIn / 12.0);
    dInc = dIn - 12.0 * (double)iFeet;
    printf("키 1 : %.1lfcm는 %d피트 %.6lf입니다. \n", dTall1, iFeet, dInc);

    dIn = dTall2 / 2.54;
    iFeet = (int)(dIn / 12.0);
    dInc = dIn - 12.0 * (double)iFeet;
    printf("키 2 : %.1lfcm는 %d피트 %.6lf입니다. \n", dTall2, iFeet, dInc);

    dIn = dTall3 / 2.54;
    iFeet = (int)(dIn / 12.0);
    dInc = dIn - 12.0 * (double)iFeet;
    printf("키 3 : %.1lfcm는 %d피트 %.6lf입니다. \n", dTall3, iFeet, dInc);
}

void Step4()
{
    //실습 2
    const double PI = 3.14;
    double dRadius = 0;
    double dResult1 = 0;
    double dResult2 = 0;

    printf("반지름을 입력하시오 : ");
    scanf_s("%lf", &dRadius);

    dResult1 = PI * 4.0 * dRadius * dRadius;
    dResult2 = PI * 4.0 / 3.0 * dRadius * dRadius * dRadius;

    printf("표면적 : %lf\n", dResult1);
    printf("체적 : %lf\n", dResult2);

}

int main()
{



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
