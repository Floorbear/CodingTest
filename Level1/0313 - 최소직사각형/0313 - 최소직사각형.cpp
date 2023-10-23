#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    std::vector<int> First;
    std::vector<int> Last;
    //sizes 앞에 큰거 오게 정리
    for (int i = 0; i < sizes.size(); i++)
    {
        int Num1 = sizes[i][0];
        int Num2 = sizes[i][1];
        if (Num2 > Num1)
        {
            sizes[i][0] = Num2;
            sizes[i][1] = Num1;
        }
        First.push_back(sizes[i][0]);
        Last.push_back(sizes[i][1]);
    }

    int SizeX = *std::max_element(First.begin(), First.end());
    int SizeY = *std::max_element(Last.begin(), Last.end());

    answer = SizeX * SizeY;


    return answer;
}

int main()
{
    solution({ {60, 50},{30, 70},{60, 30},{80, 40} });//return 4000
}

