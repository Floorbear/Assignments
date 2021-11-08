#include <iostream>
#include <vector>

using namespace std;


// -------------------------------------------------------------  선  언 -----------------------------------------------------------------------------------------------
//5개 이하 리스트에서 Insertion Sort를 이용해서 원하는 Index의 key값을 찾는 함수
int InsertionSort(vector<int> list, int want_index);

//메인 알고리즘
int LinearTimeSelection(vector<int> list, int want_index, int split_size);

// ----------------------------------- 정 의 --------------------------------------------------------------------------------------------------------------------------------

int InsertionSort(vector<int> list, int want_index)
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
    cout << "hi" << endl;
}




int main()
{
    vector<int> new_list = { 3,7,8,2,5,6 };
    cout << LinearTimeSelection(new_list,4,2);
}


