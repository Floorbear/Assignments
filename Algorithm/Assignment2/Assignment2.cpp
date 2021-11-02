#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

#define Infinity 9999

using namespace std;


//---------------------------------------- 선언 -----------------------------------------------------------------------------------------------------------------


class Edge
{
public:
    Edge(int vertexIndex, int vertexWeight);
    int connectedVertex_Index;
    int distance;
private:

};

class Graph
{
public:
    ~Graph();
    vector<Edge>* vertexList; //각각의 인덱스는 정점의 번호를 표현하는 리스트 자료구조
    void InitalizeGraph(int _vertex_count, int _edge_count); //vertexList, vertex count, edge count를 초기화 하는 함수
    int vertex_count;
    int edge_count;

private:

};

Graph gGraph; //참조할 전역변수 그래프


//현재 cpp파일과 같은 디렉토리에 있는 List.txt 파일을 불러오고, 읽은 값을 초기화 시켜주는 함수
void ReadFile();

//Dijkstra 알고리즘을 이용해 주 정점 사이의 최단걸이 길이를 반환해주는 함수 vertex_a : 시작지점, vertex_b : 도착 지점
int FindShortestPath(int vertex_a, int vertex_b);

//리스트 Q에서 가장작은 d값을 가진 정점 u를 반환하는 함수
int extractMin(vector<int>& Q, int* d);



//-------------------------------------------정  의 --------------------------------------------------------------------------------------------------------------



//Edge는 생성자로 도착지 정점의 인덱스 주소와 distance를 초기화 받는다
Edge::Edge(int vertexIndex, int vertexWeight) : connectedVertex_Index(vertexIndex), distance(vertexWeight)
{
}


Graph::~Graph()
{
}

void Graph::InitalizeGraph(int _vertex_count, int _edge_count)
{
    vertexList = new vector<Edge>[_vertex_count+1]; // 0번 인덱스는 사용하지 않는다.
    vertex_count = _vertex_count;
    edge_count = _edge_count;
}



void ReadFile()
{
    ifstream file("List.txt");
    string str;
    stringstream ss;

    //첫번째 줄을 읽어서 Vertex와 Edge의 갯수를 초기화한다.
    getline(file, str);
    ss.str(str);
    int vertex_count, edge_count;
    ss >> vertex_count;
    ss >> edge_count;
    gGraph.InitalizeGraph(vertex_count, edge_count);


    //(2 ≤ N ≤ 800, 0 ≤ E ≤ 200,000)조건을 만족하지 않으면 오류메시지를 출력한다
    if (gGraph.vertex_count < 2 || gGraph.vertex_count > 800)
    {
        cout << "****** Warning : 2 ≤ N ≤ 800 을 만족하지 않습니다....... 현재 불러온 Vertex의 개수 N : " << gGraph.vertex_count << endl;
        return;
    }
    if (gGraph.edge_count < 0 || gGraph.edge_count >200000)
    {
        cout << "****** Warning : 0 ≤ E ≤ 200,000 을 만족하지 않습니다....... 현재 불러온 Edge의 개수 E : " << gGraph.edge_count << endl;
        return;
    }

    
    //List를 한줄씩 읽으면서 Graph를 초기화한다.
    for (int i = 0; i <edge_count; i++)
    {
        int vertex_a, vertex_b, distance;

        //한 줄을 읽은 다음 읽은 줄을 스트링스트림에 넣고 vertex_a, vertex_b, distance를 초기화한다.
        string temp;
        getline(file, temp);
        stringstream ss(temp);
        ss >> vertex_a;
        ss >> vertex_b;
        ss >> distance;

        //Edge를 생성하고 gGraph에 넣어준다. 양방향이니 해당작업은 2번씩
        Edge newEdge_1(vertex_b, distance); //a -> b
        Edge newEdge_2(vertex_a, distance); //b -> a

        gGraph.vertexList[vertex_a].push_back(newEdge_1);
        gGraph.vertexList[vertex_b].push_back(newEdge_2);

    }

    //vector리스트에 있는 모든 자료 뿜어내기
    /*for (vector<Edge>::iterator i = gGraph.vertexList[4].begin(); i != gGraph.vertexList[4].end(); i++)
    {
        cout << (*i).connectedVertex_Index << endl;
    }*/


}

int extractMin(vector<int>& Q, int* d)
{
    int u = Q.front();
    for (int i : Q) //Q를 순회에 가장 작은 distance를 구한다
    {
        //현재 순회값이 이전 순회값보다 작다면 update한다
        if (d[i] < d[u])
            u = i;
    }
    return u;
}

int FindShortestPath(int vertex_a, int vertex_b)
{
    //방문한 vertex의 리스트
    vector<int> S;

    //V-S를 의미하는 리스트 VsubS
    vector<int> VsubS;

    //거리를 저장할 List
    int* distance_List = new int[gGraph.vertex_count+1]; //index 0은 사용하지 않는다

    //거리를 무한대로 초기화하고, VsubS에 모든 정점을 넣어준다
    for (int i = 1; i < gGraph.vertex_count + 1; i++)
    {
        distance_List[i] = Infinity;
        VsubS.push_back(i);
    }

    //시작 지점의 distance를 0으로 초기화 한다
    distance_List[vertex_a] = 0;

    // "방문한 vertex != 모든 vertex"일때 까지 반복한다
    while (S.size() != gGraph.vertex_count)
    {
        //집합 V-S에서 가장 distance가 작은 정점 u를 고른다
        int u = extractMin(VsubS, distance_List);

        //u를 집합 S에 넣어준다
        S.push_back(u);
        //VsubS에서 u를 지워준다
        VsubS.erase(find(VsubS.begin(), VsubS.end(), u));

        //u와 연결된 노드를 검색한다
        for (Edge v : gGraph.vertexList[u])
        {
            // v가 방문하지 않은 노드이며, d[u] + 엣지의 거리가 d[v] 보다 작다면 relaxation해준다
            if (find(VsubS.begin(), VsubS.end(), v.connectedVertex_Index) != VsubS.end() && distance_List[u] + v.distance < distance_List[v.connectedVertex_Index])
            {
                distance_List[v.connectedVertex_Index] = distance_List[u] + v.distance;
            }
        }
    }

    //정점 a와 정점 b가 연결되지 않았다면 -1을 반환한다
    if (distance_List[vertex_b] == Infinity)
        return -1;
    return distance_List[vertex_b];
}





int main()
{
    ReadFile();
    
    cout << FindShortestPath(1, 6) << endl;

}