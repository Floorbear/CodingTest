#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    answer.push_back(arr[0]);
    for (int i = 0; i < arr.size(); i++)
    {
        if (answer[answer.size() - 1] == arr[i])
        {
            continue;
        }
        answer.push_back(arr[i]);
    }

    return answer;
}

int main()
{
    solution({ 4,4,4,3,3 });//return 1, 3 , 0 ,1
}