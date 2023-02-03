#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    std::vector<int> answer;
    int Greater = 0;
    int Less = 0;
    if (n > m)
    {
        Greater = n;
        Less = m;
    }
    else
    {
        Greater = m;
        Less = n;
    }

    //최대 공약수
    std::vector<int> Divisor;
    for (int i = 1; i <= Less; i++)
    {
        if (Less % i == 0)
        {
            Divisor.push_back(i);
        }
    }

    for (int i = Divisor.size() - 1; i >= 0; i--)
    {
        if (Greater % Divisor[i] == 0)
        {
            answer.push_back(Divisor[i]);
            break;
        }
    }

    //최소 공배수
    answer.push_back(n * m / answer[0]);

    return answer;
}

int main()
{
    solution(3, 12);//return 3, 12
}

