#include <string>
#include <vector>
#include <utility>

using namespace std;

std::pair<int, int> GetStringCount(std::string _Str) //첫번째 숫자값, 두번째 뛰어넘어야하는 값
{
    if (_Str[0] == 'o')//one
    {
        return std::pair<int, int>(1,2);
    }
    else if (_Str[0] == 'z')
    {
        return std::pair<int, int>(0, 3);
    }
    else if (_Str[0] == 'e')
    {
        return std::pair<int, int>(8, 4);
    }
    else if (_Str[0] == 'n')
    {
        return std::pair<int, int>(9, 3);
    }
    else if (_Str[0] == 't')
    {
        if (_Str[1] == 'w')
        {
            return std::pair<int, int>(2, 2);
        }
        else if (_Str[1] == 'h')
        {
            return std::pair<int, int>(3, 4);
        }
    }
    else if (_Str[0] == 'f')
    {
        if (_Str[1] == 'o')
        {
            return std::pair<int, int>(4, 3);
        }
        else if (_Str[1] == 'i')
        {
            return std::pair<int, int>(5, 3);
        }
    }
    else if (_Str[0] == 's')
    {
        if (_Str[1] == 'i')
        {
            return std::pair<int, int>(6, 2);
        }
        else if (_Str[1] == 'e')
        {
            return std::pair<int, int>(7, 4);
        }
    }
}

int solution(string s) {
    int answer = 0;
    std::string sAnswer;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            sAnswer.push_back(s[i]);
            continue;
        }
        std::string TargetStr = "";
        if (i == s.size() - 1)
        {
            continue;
        }
        TargetStr.push_back(s[i]);
        TargetStr.push_back(s[i+1]);
        std::pair<int, int> Data = GetStringCount(TargetStr);
        sAnswer.push_back(Data.first + '0');
        i += Data.second;
    }

    answer = std::stoi(sAnswer);
    return answer;
}
int main()
{
    solution("2three45sixseven");//1478
    //solution("one4seveneight");//1478
}
