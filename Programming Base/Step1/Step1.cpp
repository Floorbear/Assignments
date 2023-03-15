#include <stdio.h>

void ShowSizeOfCircle()
{
    float Radius = 0;
    float Pie = 3.14f;
    float Answer = 0;

    printf("원의 반지름을 입력해 주세용 \n");
    scanf_s("%f", &Radius);
    Answer = Radius * Radius * Pie;

    printf("원의 면적은 %f 입니다! \n", Answer);
}


void ShowWonToDollar()
{
    float Dollar = 0.f;
    int Won = 0;

    printf("원화를 입력해 주세용\n");
    scanf_s("%d", &Won);
    Dollar = (float)Won / 1303.5;

    printf("달러 : %.3f$", Dollar);
}

void ShowSumNAverage()
{
    double Double1 = 0;
    double Double2 = 0;
    double Double3 = 0;

    double Sum = 0;
    double Average = 0;

    printf("첫번째 Double 값을 입력해 주세용 : ");
    scanf_s("%lf", &Double1);

    printf("두번째 Double 값을 입력해 주세용 : ");
    scanf_s("%lf", &Double2);

    printf("세번째 Double 값을 입력해 주세용 : ");
    scanf_s("%lf", &Double3);

    Sum = Double1 + Double2 + Double3;
    Average = Sum / 3;

    printf("합계는 : %f 이고 평균은 %f 입니다. \n", Sum, Average);

}

void ShowSizeNRound()
{
    double XLength = 0;
    double YLength = 0;
    double Size = 0;
    double Round = 0;

    printf("가로 길이를 입력해 주세용 : ");
    scanf_s("%lf", &XLength);
    printf("세로 길이를 입력해 주세용 : ");
    scanf_s("%lf", &YLength);

    Size = XLength * YLength;
    Round = 2 * XLength + 2 * YLength;
    printf("면적은 %lf 입니다. 둘레는 %lf 입니다. \n ",Size,Round);

}

int main()
{
    ShowSizeNRound();
}


