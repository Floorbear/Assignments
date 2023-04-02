#include <iostream>
#include <chrono>
#define WIDTH 32
#define HEIGHT 64

//void Init(float* _P, int _Width, int _Value)
//{
//	for (int i = 0; i < _Width; i++)
//	{
//		_P[i] = rand() % 3 - 1.0;
//	}
//}

/*!
* @brief 두 행렬을 곱하는 함수
* @param	float* _P
* @remarks

*/
void MultMatCPU(float* _P, float* M, float* _N, int m,int p, int n)
{
	// M = m by p  , N = p by n , P = m by n
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			float Sum = 0.0f;
			for (int k = 0; k < p; k++)
			{
				//2차원 배열을 1차원 배열로 인덱싱 하는 것 :: !! 이해 잘해 !!
				Sum = Sum + M[i * p + k] * _N[k * n + j];
			}
			_P[i * n + j] = Sum;
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
	float* arSum = new float[HEIGHT * HEIGHT]; // P = M * N = 64 * 64
	float* arM = new float[WIDTH * HEIGHT]; // M = 64 * 32
	float* arN = new float[HEIGHT * WIDTH]; // N = 32 * 64

	for (int i = 0; i < WIDTH * WIDTH; i++)
	{
		arM[i] = rand() % 3 - 1.0;
		arN[i] = rand() % 3 - 1.0;
		//arSum[i] = 0;
	}
	memset(arSum, 0, HEIGHT * HEIGHT * sizeof(float));
	//PrintMat(arM, INDEX);
	//PrintMat(arN, INDEX);
	//PrintMat(arSum, INDEX);

	std::chrono::system_clock::time_point St = std::chrono::system_clock::now();
	MultMatCPU(arSum, arM, arN,HEIGHT,WIDTH,HEIGHT);
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

