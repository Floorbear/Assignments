#include <iostream>
#include <vector>
#include <random>

#define INFINITY 1000

using namespace std;

//minimum depth value를 저장할 변수
vector<int> Output[50];

//horizontal에 대한 minimum depth value를 리턴하는 함수
vector<int> FindDepthValue(vector<int>(&depth_table)[5]);


int main()
{
    //동일한 시험군을 이용해야하므로 랜덤 시드를 고정
    std:mt19937 gen(3631);
    //분포 정의 >> 0부터 10까지 균등한 확률로 정의
    std::uniform_int_distribution<int> dis(0, 10);
    //each row에 있는 5*100테이블 [vertical][depth_value], column value
    vector<int> depth_table[50][5];
    
    //depth_table 초기화
    for (int i= 0; i < 50;i++) //vertical
    {

        for (int j = 0; j < 5; j++) //depth_value
        {
            for (int k = 0; k < 100; k++) //horizontal
            {
                //0~10 사이의 난수 생성
                int num = dis(gen);
                //난수를 넣어준다
                depth_table[i][j].push_back(num);
            }
        }
    }

    //Minimum Depth Value를 찾는다
    for (int i = 0; i < 50; i++)
    {
        //각줄의 table에 대해 Find Depth Value 진행하고 결과값을 new_List에 저장
        vector<int> new_List = FindDepthValue(depth_table[i]);

        //new_List에 저장된 값을 Output에 복사
        for (int j : new_List)
        {
            Output[i].push_back(j);
        }
    }

    //Output 출력
    for (int i = 0; i < 50; i++)
    {
        for (int j : Output[i])
        {
            cout << j << " ";
        }
        printf("\n\n");
    }
}

vector<int> FindDepthValue(vector<int>(&depth_table)[5])
{
    //return 값을 저장한 벡터
    vector<int> new_list;

    //horizontal
    for (int i = 0; i < 100; i++)
    {
        //i=0일때 예외처리 >> 첫 열에서 가장작은 depth value를 저장한다
        if (i == 0)
        {
            //가장 작은 Index를 저장할 변수
            int current_depth_value = 0;
            //가장 작은 Index의 Cost을 저장할 변수
            int cuuurent_cost = INFINITY;
            //vertical
            for (int j = 0; j < 5; j++)
            {
                int cost = depth_table[j][0];
                //현재 코스트 총합이 더 작다면 Update
                if (cuuurent_cost > cost)
                {
                    current_depth_value = j;
                    cuuurent_cost = cost;
                }
            }
            //가장 작은 depth_value를 newlist에 넣어준다
            new_list.push_back(current_depth_value);
            continue;
        }

        int current_cost = INFINITY;
        int current_depth_value = 0;
        int prev_depth_value = new_list.back();
        int prev_cost = depth_table[prev_depth_value][i - 1];

        //vertical
        for (int j = 0; j < 5; j++)
        {
            //smoothness = 이전 depth value - 현 depth value의 절댓값
            int smoothness = abs(j - prev_depth_value);
            //이전 코스트 + 현재 코스트 + smoothness*감마
            int cost = prev_cost + smoothness * 5 + depth_table[j][i];
            //현재 코스트 총합이 더 작다면 Update
            if (current_cost > cost)
            {
                current_cost = cost;
                current_depth_value = j;
            }
        }
        //가장 작은 depth_value를 newlist에 넣어준다
        new_list.push_back(current_depth_value);

    }
    return new_list;
}
