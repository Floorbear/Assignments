﻿#include <stdio.h>

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
    float Won = 0;

    printf("원화를 입력해 주세용\n");
    scanf_s("%f", &Won);
    Dollar = Won / 1300.16f;

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

int main()
{
    ShowSumNAverage();
}


