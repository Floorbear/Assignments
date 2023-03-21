#include <iostream>


int main()
{
    unsigned long long llTime = 0;
    unsigned long long Year = 0;
    unsigned long long Date = 0;
    unsigned long long Hour = 0;
    unsigned long long Minutes = 0;
    unsigned long long Seconds = 0;

    scanf_s("%llu", &llTime);

    Seconds = llTime % 60;
    llTime = llTime / 60;

    Minutes = llTime % 60;
    llTime = llTime / 60;

    Hour = llTime % 24;
    llTime = llTime / 24;
    
    Date = llTime % 365;
    llTime = llTime / 365;

    Year = llTime;

    printf("년 : %llu\n월 : %llu\n시간 : %llu\n분 : %llu\n초 : %llu\n", Year, Date, Hour, Minutes, Seconds);

    
}
