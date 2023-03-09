#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;


class ReportManager
{
    int ReportCut = 0;
    std::vector<int> ReportedCount;
    std::multimap<std::string, std::string> ReportList;
    std::vector<bool> IsBlackList;
    std::unordered_map<std::string, int> StrToInt;

public:
    ReportManager(int k)
    {
        ReportCut = k;
    }
    void Insert(std::string _Reporter, std::string _Reported)
    {
        std::multimap<std::string, std::string>::iterator Iter = ReportList.lower_bound(_Reporter);
        bool Flag = true;
        for (; Iter != ReportList.upper_bound(_Reporter); Iter++)
        {
            if (Iter->second == _Reported)
            {
                Flag = false;
            }
        }

        if (Flag == true)
        {
            ReportList.insert(std::make_pair(_Reporter, _Reported));

        }
   /*     if (find(ReportList.begin(), ReportList.end(), _Report) == ReportList.end())
        {
            ReportList.push_back(_Report);
            int Index = StrToInt[_Report.Reported];
            if (++ReportedCount[Index] >= ReportCut)
            {
                IsBlackList[Index] = true;
            }
        }*/
    }

    void CalculateReported()
    {
        std::multimap<std::string, std::string>::iterator Begin = ReportList.begin();
        for (; Begin != ReportList.end(); Begin++)
        {
          int index = StrToInt[Begin->second];
          int Count =  ++ReportedCount[index];
          if (Count >= ReportCut)
          {
              IsBlackList[index] = true;
          }
        }
    }
    void SetID(std::string _Str , int ID)
    {
        StrToInt[_Str] = ID;
        ReportedCount.resize(ID + 1);
        IsBlackList.resize(ID + 1,false);   
    }

    std::vector<int> GetResult()
    {
        std::vector<int> Result;
        std::vector<std::string> StrList;
        Result.resize(IsBlackList.size());
        StrList.resize(IsBlackList.size());

        std::unordered_map<std::string, int>::iterator StrIter = StrToInt.begin();
        for (; StrIter != StrToInt.end(); StrIter++)
        {
            StrList[StrIter->second] = StrIter->first;
        }

        //내가 신고했는지 확인
        for (int i = 0; i < StrList.size(); i++)
        {
            std::multimap<std::string, std::string>::iterator Iter = ReportList.lower_bound(StrList[i]);
            for (; Iter != ReportList.upper_bound(StrList[i]); Iter++)
            {
                if (IsBlackList[StrToInt[Iter->second]] == true)
                {
                    Result[i]++;
                }        
            }
        }

        return Result;

    }

};

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    ReportManager Manager(k);

    for (int i = 0; i < id_list.size(); i++)
    {
        Manager.SetID(id_list[i], i);
    }

    for (int i = 0; i < report.size(); i++)
    {
        stringstream ss;
        ss.str(report[i]);
        std::string Token1;
        std::string Token2;
        ss >> Token1;
        ss >> Token2;
        Manager.Insert(Token1,Token2);
    }
    Manager.CalculateReported();
    return Manager.GetResult();
}


int main()
{
    solution({ "con", "ryan" }, { "ryan con", "ryan con", "ryan con", "ryan con" },3);//2,1,1,0
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
