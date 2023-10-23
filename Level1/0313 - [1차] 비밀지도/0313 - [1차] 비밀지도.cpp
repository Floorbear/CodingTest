#include <string>
#include <vector>

using namespace std;

std::string ChangeBinary(int _Num , int _Size)
{
    std::vector<int> Digit;
    int Count = 0;
    while (Count < _Size)
    {
        Count++;
        int Num = _Num / 2;
        if (Num == 0 && Count < _Size)
        {
            Digit.push_back(_Num);
            _Num /= 2;
            Count++;
        }

        Digit.push_back(_Num % 2);
        _Num /= 2;
    }

    std::string Str = "";
    for (int i = Digit.size()-1; i >= 0; i--)
    {
        Str.push_back(Digit[i] + '0');
    }

    return Str;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    std::vector<std::string> Map1;
    std::vector<std::string> Map2;

    for (int i = 0; i < arr1.size(); i++)
    {
        Map1.push_back(ChangeBinary(arr1[i],n));
        Map2.push_back(ChangeBinary(arr2[i],n));
    }

    //지도 디코드
    for (int i = 0; i < n; i++)
    {
        std::string Row = "";
        for (int j = 0; j < n; j++)
        {
            char RowData;
            char Map1Node = Map1[i][j];
            char Map2Node = Map2[i][j];
            if (Map1Node == Map2Node)
            {
                if (Map1Node == '1')
                {
                    RowData = '#';
                }
                else
                {
                    RowData = ' ';
                }

            }
            else
            {
                RowData = '#';
            }
            Row.push_back(RowData);
        }
        answer.push_back(Row);
    }

    return answer;
}

int main()
{
    //ChangeBinary(28);
    solution(5, { 9, 20, 28, 18, 11 }, { 30, 1, 21, 17, 28 });
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
