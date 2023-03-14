#include <iostream>
#include <time.h>
#include <stdlib.h>
# define INDEXCOUNT 100000000

void AddCPU(float* _Des, float* _Target1, float* _Target2, int _IndexCount)
{
    for (int i = 0; i < _IndexCount; i++)
    {
        _Des[i] = _Target1[i] + _Target2[i];
    }
}


void PrintArray(float* _Array, int _IndexCount)
{
    for (int i = 0; i < _IndexCount; i++)
    {
        printf("%.5f   ", _Array[i]);
    }
    printf("\n");
}

int main()
{
    float* Arr1 = new float[INDEXCOUNT];
    float* Arr2 = new float[INDEXCOUNT];
    float* ArrSum = new float[INDEXCOUNT];

    for (int i = 0; i < INDEXCOUNT; i++)
    {
        Arr1[i] = rand() / static_cast<float>(RAND_MAX);
        Arr2[i] = -Arr1[i];
        ArrSum[i] = -1.f;
    }
    //PrintArray(Arr1, INDEXCOUNT);
    //PrintArray(Arr2, INDEXCOUNT);
    clock_t cStart = clock();
    AddCPU(ArrSum, Arr1, Arr2,INDEXCOUNT);
    clock_t cEnd = clock();
   // PrintArray(ArrSum, INDEXCOUNT);

    printf("경과 시간 : %u (ms)", cEnd - cStart);

    delete[] Arr1;
    delete[] Arr2;
    delete[] ArrSum;
}

