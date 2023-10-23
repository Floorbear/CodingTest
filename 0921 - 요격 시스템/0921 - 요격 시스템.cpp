
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

struct Pos2
{
    int x = 0;
    int y = 0;

    bool IsInRange(int _Value)
    {
        if (_Value > x && _Value < y)
            return true;

        return false;
    }


    bool IsInRange(Pos2 _Value)
    {
        if (_Value.x > x  && _Value.x < y )
            return true;

        if (_Value.y > x && _Value.y < y)
            return true;

        if (_Value.x == x && _Value.y == y)
            return true;

        return false;
    }

    bool IsInRange(float _x,float _y)
    {
        if (_x > x && _x < y)
            return true;

        if (_y > x && _y < y)
            return true;

        if (_x == x && _y == y)
            return true;

        return false;
    }

    int GetLength()
    {
        return y - x;
    }

    bool operator==(const Pos2& _Compare)
    {
        if (_Compare.x == this->x && _Compare.y == this->y)
            return true;

        return false;
    }

    float GetCenter()
    {
        return (float)(x + y) / 2.f;
    }

};

Pos2 FindShortestMissile(const std::list<Pos2>& _Missiles)
{
    Pos2 ShortestMissile;
    for (auto Missile : _Missiles)
    {
        if(ShortestMissile.GetLength() == 0)
            ShortestMissile = Missile;

        if (Missile.GetLength() < ShortestMissile.GetLength())
        {
            ShortestMissile = Missile;
        }
    }

    return ShortestMissile;
}

std::list<Pos2> FindOverlappedMissiles(Pos2 _Scope,std::list<Pos2>& _Missiles)
{
    std::list<Pos2> LeftOverlapped;
    std::list<Pos2> RightOverlapped;
    for (auto Missile : _Missiles)
    {
        if (Missile.IsInRange(_Scope.x, _Scope.GetCenter()))
        {
            LeftOverlapped.push_back(Missile);
        }

        if (Missile.IsInRange(_Scope.GetCenter(), _Scope.y))
        {
            RightOverlapped.push_back(Missile);
        }
    }


    if (LeftOverlapped.size() >= RightOverlapped.size())
    {
        return LeftOverlapped;
    }
    else
    {
        return RightOverlapped;
    }
}

int solution(std::vector<std::vector<int>> targets) {
    int answer = 0;

    //미사일들 저장
    std::list<Pos2> Missiles;
    for (auto target : targets)
    {
        Pos2 NewMissle;
        NewMissle.x = target[0];
        NewMissle.y = target[1];
        Missiles.push_back(NewMissle);
    }

    while (Missiles.empty() != true)
    {
        std::list<Pos2> ShouldRemoveMissiles = FindOverlappedMissiles(FindShortestMissile(Missiles), Missiles);
        for (std::list<Pos2>::iterator i = ShouldRemoveMissiles.begin(); i != ShouldRemoveMissiles.end(); ++i)
        {
            Missiles.remove_if([&](Pos2& _Other) { return _Other == *i; });
        }
        answer++;
    }


    


    return answer;
}

int main()
{
    //solution([[4,5],[4,8],[10,14],[11,13],[5,12],[3,7],[1,4]])
    solution({ {4,5},{4,8},{10,14},{11,13},{5,12},{3,7},{1,4} }); //result = 3
}
