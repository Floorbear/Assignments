﻿#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;


//---------------------------------------- 선언 -----------------------------------------------------------------------------------------------------------------


class Vertex
{
public:
    ~Vertex();
    vector<int> connectedVertex_Index_LIst;

private:

};

class Edge
{
public:
    Edge(int vertexIndex, int vertexWeight);
    int connectedVertex_Index;
    int distance;
private:

};


//그래프 인덱스는 정점의 번호
vector<Edge> Graph[800];


//현재 cpp파일과 같은 디렉토리에 있는 List.txt 파일을 불러오고, 읽은 값을 초기화 시켜주는 함수
void ReadFile();





//-------------------------------------------정  의 --------------------------------------------------------------------------------------------------------------


Vertex::~Vertex()
{
}

Edge::Edge(int vertexIndex, int vertexWeight) : connectedVertex_Index(vertexIndex), distance(vertexWeight)
{
}





void ReadFile()
{
    ifstream file("List.txt");
    string str;
    stringstream ss;

    //첫번째 줄을 읽어서 Vertex와 Edge의 갯수를 초기화한다.
    getline(file, str);
    ss.str(str);
    ss >> gGraph.vertex_count;
    ss >> gGraph.edge_count;

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

    //Vertex의 갯수만큼 vertexList초기화
    for (int i = 0; i < gGraph.vertex_count; i++)
    {
        Vertex newVertex;
        gGraph.vertexList.push_back(newVertex);
    }
    //Edge의 갯수만큼 edgeList 초기화
    for (int i = 0; i < gGraph.edge_count; i++)
    {
        Edge newEdge;
        gGraph.edgeList.push_back(newEdge);
    }
    //File의 아랫줄을 불러들여 


}





int main()
{
    ReadFile();
    cout << gGraph.vertex_count << "       " << gGraph.edge_count << endl;
    cout << "Update" << endl;
}