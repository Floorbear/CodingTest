#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		int DivValue = i + 1;
		if (n % DivValue == 0)
		{
			answer += DivValue;
		}
	}
	return answer;
}
int main()
{
	solution(12);
}