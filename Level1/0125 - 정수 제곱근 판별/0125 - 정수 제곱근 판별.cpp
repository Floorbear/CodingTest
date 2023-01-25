#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
	long long answer = 0;

	double Value = sqrt(n);
	if (Value - static_cast<int>(Value) > 0)
	{
		return -1;
	}

	Value += 1;
	answer = pow(Value, 2);

	return answer;
}

int main()
{
	solution(121);
}