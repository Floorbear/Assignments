#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std;


// -------------------------------------------------------------  선  언 -----------------------------------------------------------------------------------------------
//5개 이하 리스트에서 Insertion Sort를 이용해서 원하는 Index의 key값을 찾는 함수
int InsertionSort(vector<int>& list, int want_index);

//메인 알고리즘
int LinearTimeSelection(vector<int> list, int want_index, int split_size);

//텍스트 파일을 읽어서 Number을 list에 저장하는 함수
vector<int> ReadTextFile(int readType);//readType 0 : n(100)짜리 파일 읽음 1:n(1000)짜리 파일 읽음 2: n(10000)짜리 파일 읽음 

// ----------------------------------- 정 의 --------------------------------------------------------------------------------------------------------------------------------

int InsertionSort(vector<int>& list, int want_index)
{
    if (list.size() == 1) //list의 사이즈가 1이면 그냥 반환
    {
        return list.front();
    }


    for (vector<int>::iterator i = list.begin() + 1; i < list.end(); i++)
    {
        auto temp = i;
        while (temp != list.begin() && *temp < *(temp - 1))
        {
            iter_swap(temp, temp - 1);
            temp--;
        }
    }
    return list[want_index - 1];
}

int LinearTimeSelection(vector<int> list, int want_index, int split_size)
{
    //elements의 숫자가 split_size 보다 작으면 InsertionSort를 이용해 원하는 element를 찾는다
    if (list.size() <= split_size)
    {
        return InsertionSort(list, want_index);
    }

    // n/split_size 만큼의 그룹을 생성한다
    int group_count;
    if (list.size() % split_size == 0)
    {
        group_count = list.size() / split_size;
    }
    else
    {
        group_count = list.size() / split_size + 1;
    }
    vector<int>* group = new vector<int>[group_count];

    //각 그룹에 split_size만큼 element를 넣어준다
    for (int i = 0; i < group_count; i++)
    {
        for (int j = 0; j < split_size; j++)
        {
            if (!list.empty())
            {
                group[i].push_back(list.front());
                list.erase(list.begin());
            }
            else
                break;
            
        }
    }

    //각 그룹의 median을 찾아서 리스트 M에 넣어준다
    vector<int> M;
    for (int i = 0; i < group_count; i++)
    {
        M.push_back(InsertionSort(group[i], group[i].size() / 2 + 1)); //group의 중간값을 찾아서 M에 넣어준다
    }

    //M의 중간값을 재귀적으로 찾아준다
    int mom = LinearTimeSelection(M, M.size() / 2 + 1, split_size);

    //모든 그룹을 순회에 mom보다 작거나 같으면 M1에 넣고, mom보다 크면 M2에 넣는다 == mom이 pivot이 된다
    vector<int> M1;
    vector<int> M2;
    for (int i = 0; i < group_count; i++)
    {
        for (int i : group[i])
        {
            if (i <= mom)
                M1.push_back(i);
            else
                M2.push_back(i);
        }
    }

    //이렇게 되면 M1에 pivot(mom)이 포함되는데, M1에서 pivot과 같은 값을 1개 지워준다 == 불안정 정렬이 된다
    M1.erase(find(M1.begin(), M1.end(), mom));

    //want_index가 M1사이즈 보다 작으면 M1을 재귀호출, want_index와 mom의 위치가 같으면 mom을 리턴 , want_index가 mom의 위치보다 크면 M2를 재귀호출
    if (want_index <= M1.size())
        return LinearTimeSelection(M1, want_index, split_size);
    else if (want_index == M1.size() + 1)//pivot위치
        return mom;
    else
        return LinearTimeSelection(M2, want_index - (M1.size() + 1),split_size);
  
}

vector<int> ReadTextFile(int readType)
{
    vector<int> newVector; //반환할 벡터

    ifstream file;

    //readType에 따라 서로다른 List파일을 불러온다
    switch (readType)
    {
        case 0: //n100
            file.open("List_100.txt"); //List 파일을 ifstream객체 형태로 불러온다
            break;
        case 1: // n = 1000
            file.open("List_1000.txt"); 
            break;
        case 2: // n = 10000
            file.open("List_10000.txt");
            break;
    default:
        break;
    }

    stringstream ss; 
    ss << file.rdbuf(); // ss 버퍼에 file에 있는 내용을 넣어준다

    while (!ss.eof()) //ss의 버퍼에 있는 숫자를 newVector에 넣어준다
    {
        int n;
        ss >> n;
        newVector.push_back(n);
    }
    return newVector;
}




int main()
{
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    vector<int> testVector = ReadTextFile(2);
    std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;

    int want_index = 5000;
    cout << want_index<<"번째 숫자 : " << LinearTimeSelection(testVector, want_index, 7) << endl;
    cout << sec.count() << endl;
}


