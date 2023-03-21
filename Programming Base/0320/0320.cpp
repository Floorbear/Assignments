
#include <iostream>

void Step1()
{
    int iInput = 0;
    printf("16진수 정수를 입력하세용 : ");
    scanf_s("%x", &iInput);

    printf("8진수로는 %o 입니다. \n", iInput);
    printf("10진수로는 %d 입니다. \n", iInput);
    printf("16진수로는 Ox%x 입니다. \n", iInput);
}

void Step2()
{
    printf("\"ASCII Code\", 'A', 'B', 'C' \n\\t \\a \\n \n");

}

void Step3()
{
    int iKg = 0;
    int iVel = 0;
    double Energy = 0;
    printf("질량(kg) : ");
    scanf_s("%d", &iKg);
    printf("속도(m/s) : ");
    scanf_s("%d", &iVel);

    Energy = (double)iKg * (double)iVel * (double)iVel / 2.0;
    printf("운동에너지(J) : %lf", Energy);
}


void Step4()
{
    printf("%c %c %c", 'a' + 1, 'a' + 2, 'a' + 3); //아스키

}

int main()
{
    Step3();
    //Step4();
}

