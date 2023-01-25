#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	std::string Str = s;
	int PCount = 0;
	int YCount = 0;

	for (int i = 0; i < Str.size(); i++)
	{
		char Value = Str[i];
		if (Value == 'P' || Value == 'p')
		{
			PCount++;
		}

		if (Value == 'Y' || Value == 'y')
		{
			YCount++;
		}
	}

	return PCount - YCount ? false : true;
}

int main()
{
	solution("pPoooyY");
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴