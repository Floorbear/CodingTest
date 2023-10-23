#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    bool IsVisit = false;
    int iValue = -1;

    std::vector<Node*> Edge;
};



class Graph
{
public:
    Graph(vector<string> maps);
    ~Graph();

    bool IsX(Node _Node);
    int DFS(Node* _Root); // X노드를 _Root파라미터로 넘기면 안됨
    vector<int> CheckGraph();
    

    std::vector<std::vector<Node>> vvGraph;
};

Graph::Graph(vector<string> maps)
{
    int Row = 0;
    int Col = 0;
    Row = maps.size();
    Col = maps[0].size();

    for (int i = 0; i < Row; i++)
    {
        std::vector<Node> NewVector;
        for (int j = 0; j < Col; j++)
        {
            Node NewNode;
            char CurData = maps[i][j];
            if (CurData != 'X')
            {
                NewNode.iValue = CurData - '0';
            }
            NewVector.push_back(NewNode);
        }
        vvGraph.push_back(NewVector);
    }

    //엣지 초기화
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if (IsX(vvGraph[i][j]) == true)
            {
                continue;
            }
            int Left = j - 1;
            int Right = j + 1;
            int Up = i - 1;
            int Down = i + 1;

            if (Left >= 0)
            {
                if (IsX(vvGraph[i][Left]) == false)
                {
                    vvGraph[i][j].Edge.push_back(&vvGraph[i][Left]);
                }
            }
            if (Right < vvGraph[0].size())
            {
                if (IsX(vvGraph[i][Right]) == false)
                {
                    vvGraph[i][j].Edge.push_back(&vvGraph[i][Right]);
                }
            }
            if (Up >= 0)
            {
                if (IsX(vvGraph[Up][j]) == false)
                {
                    vvGraph[i][j].Edge.push_back(&vvGraph[Up][j]);
                }
            }
            if (Down < vvGraph.size())
            {
                if (IsX(vvGraph[Down][j]) == false)
                {
                    vvGraph[i][j].Edge.push_back(&vvGraph[Down][j]);
                }
            }
        }
    }

}

Graph::~Graph()
{

}

bool Graph::IsX(Node _Node)
{
    if (_Node.iValue == -1)
    {
        return true;
    }
    return false;
}

int Graph::DFS(Node* _Root)
{
    int Result = 0;
    Result += _Root->iValue;
    _Root->IsVisit = true;

    for (Node* AdjacentNode : _Root->Edge)
    {
        if (AdjacentNode->IsVisit == false)
        {
            Result += DFS(AdjacentNode);
        }
    }
    return Result;
}


vector<int> Graph::CheckGraph()
{
    vector<int> result;
    

    for (int i = 0; i < vvGraph.size(); i++)
    {
        for (int j = 0; j < vvGraph[0].size(); j++)
        {
            if (vvGraph[i][j].iValue == -1)//X
            {
                continue;
            }
            if (vvGraph[i][j].IsVisit == true)
            {
                continue;
            }

            result.push_back(DFS(&vvGraph[i][j]));
        }
    }




    if (result.empty() == true)
    {
        result.push_back(-1);
    }


    std::sort(result.begin(), result.end(), [](int a, int b)
        {
            return a < b;
        });
    return result;
}

vector<int> solution(vector<string> maps) 
{
    vector<int> answer;
    Graph MyGraph(maps);


    return MyGraph.CheckGraph();
}

int main()
{
    vector<int> New = solution({ "X591X","X1X5X","X231X", "1XXX1" });//return {1, 1, 27}
    int a = 0;
}