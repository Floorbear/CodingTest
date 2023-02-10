#include <string>
#include <vector>

using namespace std;

struct Pos
{
    Pos(int _X, int _Y)
    {
        X = _X;
        Y = _Y;
    }
    int X;
    int Y;

    int Distance(Pos _Other)
    {
        return { abs(X - _Other.X) + abs(Y - _Other.Y) };
    }
};

class Phone
{
public:
    Phone(vector<int> _numbers, std::string _hand):Numbers(_numbers),Hand(_hand)
    {
        KeyPad.push_back(Pos(2, 4));
        KeyPad.push_back(Pos(1, 1));
        KeyPad.push_back(Pos(2, 1));
        KeyPad.push_back(Pos(3, 1));
        KeyPad.push_back(Pos(1, 2));
        KeyPad.push_back(Pos(2, 2));
        KeyPad.push_back(Pos(3, 2));
        KeyPad.push_back(Pos(1, 3));
        KeyPad.push_back(Pos(2, 3));
        KeyPad.push_back(Pos(3, 3));
    }

    std::string Calculate();

private:
    vector<int> Numbers;
    vector<Pos> KeyPad;
    std::string Hand;
};

string solution(vector<int> numbers, string hand) {
    Phone NewPhone(numbers, hand);
    return NewPhone.Calculate();
}



std::string Phone::Calculate()
{
    std::string Answer = "";
    Pos LeftHand(1, 4);
    Pos RightHand(3, 4);
    for (int NumberCount = 0; NumberCount < Numbers.size(); NumberCount++)
    {
        int Num = Numbers[NumberCount];
        if (Num == 1 || Num == 4 || Num == 7)
        {
            Answer.push_back('L');
            LeftHand = KeyPad[Num];
            continue;
        }
        if (Num == 3 || Num == 6 || Num == 9)
        {
            Answer.push_back('R');
            RightHand = KeyPad[Num];
            continue;
        }

        if (RightHand.Distance(KeyPad[Num]) < LeftHand.Distance(KeyPad[Num]))
        {
            Answer.push_back('R');
            RightHand = KeyPad[Num];
            continue;
        }
        else if (RightHand.Distance(KeyPad[Num]) == LeftHand.Distance(KeyPad[Num]))
        {
            if (Hand == "right")
            {
                Answer.push_back('R');
                RightHand = KeyPad[Num];
                continue;
            }
            else
            {
                Answer.push_back('L');
                LeftHand = KeyPad[Num];
                continue;
            }
        }
        else
        {
            Answer.push_back('L');
            LeftHand = KeyPad[Num];
            continue;
        }
    }
    return Answer;
}

int main()
{
    solution({7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 }, "left");//LRLLLRLLRRL
}