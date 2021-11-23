#include <iostream>
#include <vector>

using namespace std;

int polynomials_of_order = 0;
double value_x = 3.4;

typedef struct Pair {
	double x;
	double fx;
}Pair;



double calculate_b(vector<Pair> _pair_list) //f[xn,xn-1,....x1]을 구하는 함수
{
	if (_pair_list.size() <= 1)
		return _pair_list.front().fx;
	else if (_pair_list.size() == 2)
	{
		return (_pair_list.back().fx - _pair_list.front().fx) / (_pair_list.back().x - _pair_list.front().x);
	}

	//사이즈가 3이상일 경우 재귀적으로 구한다
	vector<Pair> left_list; //xn,xn-1,....x2
	vector<Pair> right_list;//xn-1,xn-2,.....x1

	for (int i = 0; i < _pair_list.size() - 1; i++)
	{
		Pair newPiar = *(_pair_list.begin() + i + 1); //xn,xn-1,....x2
		left_list.push_back(newPiar);
	}

	for (int i = 0; i < _pair_list.size() - 1; i++)
	{
		Pair newPiar = *(_pair_list.begin() + i); //xn-1,xn-2,.....x1
		right_list.push_back(newPiar);
	}

	return (calculate_b(left_list) - calculate_b(right_list)) / (_pair_list.back().x - _pair_list.front().x);
}

int main()
{

	vector<Pair> pair_list;

    cout << "Polynomial_order을 입력해주세요" << endl;
    cin >> polynomials_of_order;
	for (int i = 0; i < polynomials_of_order+1; i++)
	{
		Pair newPair;
		cout << "x_" << i + 1 << "의 값을 입력해주세요" << endl;
		cin >> newPair.x;
		cout << "f(x_" << i + 1 << ")의 값을 입력해주세요" << endl;
		cin >> newPair.fx;
		pair_list.push_back(newPair);
	}

	//값을 구해준다
	double want_value = 0;
	for (int i = 0; i < polynomials_of_order+1; i++)
	{
		double new_value;
		vector<Pair> newList;
		cout << "f[";
		for (int j = 0; j < i + 1; j++)
		{
			Pair newPair = *(pair_list.begin() + j);
			cout << newPair.x <<",";
			newList.push_back(newPair);
		}
		cout << "]";
		double b = calculate_b(newList);
		new_value = b;
		for (int j = 0; j < i; j++)
		{
			Pair newPair = *(pair_list.begin() + j);
			new_value *= value_x - newPair.x;
			cout << "(" << value_x << "-" << newPair.x << ")";
		}
		if(i!=polynomials_of_order)
			cout << "+";	
		want_value += new_value;
	}
	cout << "=" << endl;	
	cout << want_value << endl;

}

