#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
	vector<int> answer;
	std::string Str = std::to_string(n);
	for (int i = Str.size() - 1; i >= 0; i--)
	{
		int Value = Str[i] - '0';
		answer.push_back(Value);
	}
	return answer;
}
int main()
{
	solution(12345);
}