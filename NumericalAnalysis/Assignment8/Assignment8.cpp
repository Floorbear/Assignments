#include <iostream>
#include <vector>

using namespace std;

int polynomials_of_order = 0;
double value_x = 3.4; //원하는 x값

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

//DataPoint로 부터 NewtonsInterpolate 방식으로 다항식을 구해 value_x의 y값을 추정하고 출력하는 함수
void NewtonsInterpolate(vector<Pair> pair_list)
{
	//값을 구해준다
	double want_value = 0;
	for (int i = 0; i < polynomials_of_order + 1; i++)
	{
		double new_value;
		vector<Pair> newList;
		cout << "f[";
		for (int j = 0; j < i + 1; j++)
		{
			Pair newPair = *(pair_list.begin() + j);
			cout << newPair.x << ",";
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
		if (i != polynomials_of_order)
			cout << "+";
		want_value += new_value;
	}
	cout << "=" << endl;
	cout << want_value << endl;
}

//DataPoint로 부터 LagrangeInterpolate 방식으로 다항식을 구해 value_x에서 y값을 추정하고 출력하는 함수
void LagrangeInterpolate(vector<Pair> pair_list)
{
	double want_value = 0;
	for (int i = 0; i < polynomials_of_order+1; i++)
	{
		Pair pivot = pair_list[i]; //pivot 설정
		double newValue = pivot.fx; //for문 1회전에 구할 값

		//pair_list에서 pivot을 제외한 나머지 값을 리스트에 넣어주고 해당 리스트로 L(x)를 구한다
		vector<Pair> newList;
		for (Pair j : pair_list) //pair_list에서 pivot을 제외한 나머지값을 너어주기
		{
			if (j.x != pivot.x && j.fx != pivot.fx)
				newList.push_back(j);
		}

		for(Pair j :newList) //해당 리스트로 L(x) 구해주기
		{
			double numerator_value = value_x - j.x;
			double denominator_value = pivot.x - j.x;
			newValue = newValue * numerator_value / denominator_value;
			cout << "(" << value_x << "-" << j.x << ")/(" << pivot.x << "-" << j.x << ") ";
		}
		cout << "f(" << pivot.x << ")";
		if (i != polynomials_of_order)
			cout << "+";
		//구한 Li(x)f(xi)를 합치기
		want_value += newValue;

	}
	cout <<" =\n " << want_value << endl;
}
int main()
{

	vector<Pair> pair_list;

    cout << "Polynomial_order을 입력해주세요" << endl;
    cin >> polynomials_of_order;
	cout << "value_x의 값을 입력해주세요" << endl;
	cin >> value_x;
	for (int i = 0; i < polynomials_of_order+1; i++)
	{
		Pair newPair;
		cout << "x_" << i + 1 << "의 값을 입력해주세요" << endl;
		cin >> newPair.x;
		cout << "f(x_" << i + 1 << ")의 값을 입력해주세요" << endl;
		cin >> newPair.fx;
		pair_list.push_back(newPair);
	}

	LagrangeInterpolate(pair_list);
	//NewtonsInterpolate(pair_list);

	

}

