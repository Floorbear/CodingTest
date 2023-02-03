#include <string>
#include <vector>
#include <sstream>

using namespace std;

std::string DeleteSpace(std::string _Str)
{
    stringstream ss(_Str);
    std::string token;
    std::string Str;
    while (ss >> token)
    {
        Str += token;
    }
    return Str;
}

string solution(string new_id) {
    string answer = new_id;

    //Phase1 대문자 > 소문자 변경
    for (int i = 0; i < answer.size(); i++)
    {
        if ('A' <= answer[i] && answer[i] <= 'Z')
        {
            answer[i] += 32;
        }
    }

    //Phase2 특수문자 삭제
    for (int i = 0; i < answer.size(); i++)
    {
        if ('a' <= answer[i] && answer[i] <= 'z')
        {
            continue;
        }
        if (answer[i] == '.' || answer[i] == '_' || answer[i] == '-')
        {
            continue;
        }
        if ('0' <= answer[i] && answer[i] <= '9')
        {
            continue;
        }
        answer[i] = ' ';

    }

    //공백 제거
    answer =  DeleteSpace(answer);

    //Phase3 점제거
    bool IsDeleteDot = true;
    while (IsDeleteDot)
    {
        IsDeleteDot = false;
        for (int i = 0;i < answer.size(); i++)
        {
            if (answer[i] == '.')
            {
                if (i + 1 < answer.size())
                {
                    if (answer[i + 1] == '.')
                    {
                        answer[i + 1] = ' ';
                        IsDeleteDot = true;
                    }
                }
            }
        }
        answer = DeleteSpace(answer);
    }

    //Phase4 양 끝점 제거
    bool IsDeleteEdge = true;
    while (IsDeleteEdge)
    {
        IsDeleteEdge = false;
        if (answer[0] == '.')
        {
            answer[0] = ' ';
            IsDeleteEdge = true;
        }

        if (answer[answer.size() - 1] == '.')
        {
            answer[answer.size() - 1] = ' ';
            IsDeleteEdge = true;
        }

        answer = DeleteSpace(answer);
    }

    //Phase5 빈문자열이면 a 대입
    if (answer.empty() == true)
    {
        answer += "a";
    }

    //Phase6 길이 이상 자르기
    if (answer.size() >= 16)
    {
        answer.erase(15, answer.size() - 1);
    }

    //Phase7 문자열 늘리기
    if (answer.size() <= 2)
    {
        char C = answer[answer.size() - 1];
        for (int i = answer.size(); i < 3; i++)
        {
            answer.push_back(C);
        }
    }
   

    return answer;
}

int main()
{
    solution("abcdefghijklmn.p");//bat.y.abcdefghi
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
