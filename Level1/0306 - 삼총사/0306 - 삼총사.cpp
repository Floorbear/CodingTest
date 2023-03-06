#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int result = 0;
    for (int i = 0; i < number.size() - 2; i++)
    {
        int first = -1;
        int second = -1;
        int third = -1;

        first = number[i];
        for (int j = i + 1; j < number.size() - 1; j++)
        {
            second = number[j];
            for (int k = j + 1; k < number.size(); k++)
            {
                third = number[k];
                int sum = first + second + third;
                if (sum == 0)
                {
                    result++;
                }
            }
        }
    }

    return result;
}

int main()
{
    solution({ -2, 3, 0, 2, -5 });//return 2
}

