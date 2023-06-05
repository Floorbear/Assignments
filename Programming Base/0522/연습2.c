#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

void printArray(int _arr[], int _size)
{
	for (int i = 0; i < _size; i++)
	{
		printf("%d ", _arr[i]);
	}
	printf("\n");
}


void getArray(int _arr[], int _size)
{
	for (int i = 0; i < _size; i++)
	{
		int RandomValue = rand() % SIZE;
		_arr[i] = RandomValue;
	}
}

void swapArray(int* _a, int* _b)
{
	int tempValue = *_b;
	*_b = *_a;
	*_a = tempValue;
}


void sortArray(int _arr[], int _size, int(*sortFunc)(int, int))
{
	//bubble
	for (int i = _size - 1; i > 0; i--)
	{
		for (int j =0; j  < i; j++)
		{
			if (!sortFunc(_arr[j], _arr[j + 1]))
			{
				swapArray(&_arr[j], &_arr[j + 1]);
			}
		}
	}
}

int isBigger(int _a, int _b)
{
	return _a < _b;
}



int main()
{
	int arrA[SIZE] = {0,};

	getArray(arrA, SIZE);
	printArray(arrA, SIZE);
	sortArray(arrA, SIZE, isBigger);
	printArray(arrA, SIZE);
}


