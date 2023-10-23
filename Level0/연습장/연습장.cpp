// 연습장.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Boss
{
public:
    bool IsUsingBuff = false;
    bool IsDie = false;
};


class Servant //부하
{
public:
    void BossBuffCheck(Boss boss)
    {
        if (boss.IsUsingBuff == true)
        {
            AtkUP();
        }
    }

    void BossDieCheck(Boss boss)
    {
        if (boss.IsDie == true)
        {
            Suicide();
        }
    }

    void AtkUP()
    {
        //중복 호출 방지
        
        //공격력 증가
    }

    void Suicide()
    {
        //중복 호출 방지

        //자살
    }
};