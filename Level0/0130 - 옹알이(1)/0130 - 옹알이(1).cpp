#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
// babbling_len은 배열 babbling의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.

int GetStrSize(const char* _Str)
{
    int Size = 0;
    while (_Str[Size] != '\0')
    {
        Size++;
    }
    return Size;
}

int FindStr(const char* _Str , const char* _FindStr)
{
    int StrSize = GetStrSize(_Str);
    int FindIterSize = GetStrSize(_FindStr);
    int i = 0;
    while (_Str[i] != '\0')
    {
        if (StrSize - i < FindIterSize)
        {
            return -1;
        }
        if (_Str[i] == _FindStr[0])
        {
            bool Flag = true;
            for (int j = 0; j < FindIterSize; j++)
            {
                if (_Str[i + j] != _FindStr[j])
                {
                    Flag = false;
                    break;
                }
            }

            if (Flag == true)
            {
                return i;
            }
        }
        i++;
    }
}
const char* DeleteWord(const char* _Str, const char* _DeleteWord)
{
    int Pos = FindStr(_Str,_DeleteWord);
    if (-1 == Pos)
    {
        return _Str;
    }

    char Str[100];
    strcpy(Str, _Str);
    for (int i = 0; i < GetStrSize(_DeleteWord); i++)
    {
        Str[Pos + i] = 'O';
    }
    
    return Str;

}
int solution(const char* babbling[], size_t babbling_len) {

    //단어 제거하는 함수
    //4 번실행
    //제거할 단어가 없으면 함수 그대로 반환
    //string에 문자가 남아있으면 false 없으면 true
    //std::vector<std::string> VString;
    //for (int i = 0; i < babbling_len; i++)
    //{
    //    VString.push_back(babbling[i]);
    //}

    int Result = 0;
    for (int i = 0; i < babbling_len; i++)
    {
        char* Str = (char*)malloc(sizeof(char) * GetStrSize(babbling[i] + 1));
        strcpy(Str, babbling[i]);

        strcpy(Str, DeleteWord(Str, "aya"));
        strcpy(Str, DeleteWord(Str, "ye"));
        strcpy(Str, DeleteWord(Str, "woo"));
        strcpy(Str, DeleteWord(Str, "ma"));


        bool Flag = true;
        for (int i = 0; i < GetStrSize(Str); i++)
        {
            if (Str[i] != 'O')
            {
                Flag = false;
                break;
            }
        }

        if (Flag == true)
        {
            Result++;
        }

      
    }


    return Result;
}
int main()
{
   // DeleteWord("IamMaoKao", "Mao");
    const char* babbling[] = { "aya", "yee", "u", "maa", "wyeoo" };
    solution(babbling, 5);
}
