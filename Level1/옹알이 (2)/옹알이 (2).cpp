#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Word
{
    std::string Str = "";
    size_t Pos;

    Word(std::string _Str, size_t _Pos)
    {
        Str = _Str;
        Pos = _Pos;
    }
};

std::string ChangeWord(std::string _Str, std::string _Word)
{
    size_t Pos = _Str.find(_Word);
    if (Pos == std::string::npos)
    {
        return _Str;
    }

    for (int i = 0; i < _Word.size(); i++)
    {
        _Str[i + Pos] = 'O';
    }
    return _Str;
}

bool ISAllNPos(std::vector<Word> _Vector)
{
    int Count = 0;
    for (int i = 0; i < _Vector.size(); i++)
    {
        if (_Vector[i].Pos == std::string::npos)
        {
            Count++;
        }
    }

    if (Count == _Vector.size())
    {
        return true;
    }
    return false;
}

int solution(vector<string> babbling) 
{
    int answer = 0;
    for (int i = 0; i < babbling.size(); i++)
    {
        std::string LastChangeWord = "";
        bool Flag = true;
        while (true)
        {
            std::vector<Word> Pos;
            Pos.push_back(Word("aya", babbling[i].find("aya")));
            Pos.push_back(Word("ye", babbling[i].find("ye")));
            Pos.push_back(Word("woo", babbling[i].find("woo")));
            Pos.push_back(Word("ma", babbling[i].find("ma")));

            if (ISAllNPos(Pos) == true)
            {
                //다돌았는데 더이상 없어 브레이크에 false
                for (int j = 0; j < babbling[i].size(); j++)
                {
                    if (babbling[i][j] != 'O')
                    {
                        Flag = false;
                        break;
                    }
                }
                break;
            }
            //가장 왼쪽에 있는거 검색
            std::vector<Word>::iterator Iter = std::min_element(Pos.begin(), Pos.end(), [](Word a, Word b) {return a.Pos < b.Pos; });

            if (LastChangeWord == Iter->Str)
            {
                Flag = false;
                break;
            }
            babbling[i] = ChangeWord(babbling[i], Iter->Str);
            LastChangeWord = Iter->Str;
        }
          
        //babbling[i] = ChangeWord(babbling[i], "ye");
        //babbling[i] = ChangeWord(babbling[i], "woo");
        //babbling[i] = ChangeWord(babbling[i],"ma");


        if (Flag == true)
        {
            answer++;
        }
    }
    return answer;
}

int main()
{
    solution({ "ayayeaya" });
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
