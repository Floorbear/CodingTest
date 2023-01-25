#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
	vector<long long> answer;

	for (int i = 1; i <= n; i++)
	{
		int Value = x * i;
		answer.push_back(Value);
	}
	return answer;
}

int main()
{
	solution(2, 5);
}