#include <iostream>
#include <chrono>
#define INDEX 32

//void Init(float* _P, int _Width, int _Value)
//{
//	for (int i = 0; i < _Width; i++)
//	{
//		_P[i] = rand() % 3 - 1.0;
//	}
//}
void MultMatCPU(float* _P, float* M, float* _N, int _Width)
{
	for (int i = 0; i < _Width; i++)
	{
		for (int j = 0; j < _Width; j++)
		{
			float Sum = 0.0f;
			for (int k = 0; k < _Width; k++)
			{
				//2차원 배열을 1차원 배열로 인덱싱 하는 것 :: !! 이해 잘해 !!
				Sum = Sum + M[i * _Width + k] * _N[k * _Width + j];
			}
			_P[i * _Width + j] = Sum;
		}
	}
}

void PrintMat(float* _P, int _Width)
{
	std::cout << "------------------------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < _Width; i++)
	{
		for (int j = 0; j < _Width; j++)
		{
			printf("%.1f       ", _P[i * _Width + j]);
		}
		std::cout << std::endl;
	}
}
int main()
{
	float* arSum = new float[INDEX * INDEX];
	float* arM = new float[INDEX * INDEX];
	float* arN = new float[INDEX * INDEX];

	for (int i = 0; i < INDEX * INDEX; i++)
	{
		arM[i] = rand() % 3 - 1.0;
		arN[i] = rand() % 3 - 1.0;
		arSum[i] = 0;
	}
	//PrintMat(arM, INDEX);
	//PrintMat(arN, INDEX);
	//PrintMat(arSum, INDEX);

	std::chrono::system_clock::time_point St = std::chrono::system_clock::now();
	MultMatCPU(arSum, arM, arN,INDEX);
	std::chrono::system_clock::time_point Ed = std::chrono::system_clock::now();

	std::chrono::nanoseconds Time = Ed - St;
	std::chrono::microseconds microTime = std::chrono::duration_cast<std::chrono::microseconds>((Ed - St));
	std::chrono::milliseconds milliTime = std::chrono::duration_cast<std::chrono::milliseconds>((Ed - St));
	//PrintMat(arSum, INDEX);
	printf("Elapsed Time = %lld nanoseconds \n \n", Time.count());
	printf("Elapsed Time = %lld microseconds \n \n", microTime.count());
	printf("Elapsed Time = %lld milliseconds \n \n", milliTime.count());



	delete[] arSum;
	delete[] arM;
	delete[] arN;

}

