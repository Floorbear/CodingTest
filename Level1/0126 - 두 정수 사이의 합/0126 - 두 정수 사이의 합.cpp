#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b) {
	long long answer = 0;

	std::vector<int> Nums = { a,b };
	sort(Nums.begin(), Nums.end(), std::less<int>());
	int Dif = Nums[1] - Nums[0];

	for (int i = 0; i <= Dif; i++)
	{
		answer += Nums[0] + i;
	}
	return answer;
}

int main()
{
	solution(3, 5);
}