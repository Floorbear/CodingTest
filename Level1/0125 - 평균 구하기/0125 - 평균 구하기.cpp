#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
	double answer = 0;
	int Count = 0;
	int Add = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		Count++;
		Add += arr[i];
	}

	answer = static_cast<double>(Add) / static_cast<double>(Count);
	return answer;
}
int main()
{
	solution({ 1,2,3,4 });
}