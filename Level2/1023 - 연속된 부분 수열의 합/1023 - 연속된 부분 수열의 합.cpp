#include <string>
#include <vector>

using namespace std;

struct Sequence 
{
	int StartIndex = 0;
	int EndIndex = 0;
	int GetLength()
	{
		return EndIndex - StartIndex;
	}
};

// -1 : not match
bool IsExistSubsequence(int _K, int _StartIndex,int* _EndIndex, vector<int> _Sequence,int* _SumValue)
{
	int SequenceLast = _Sequence.size() - 1;
	while (*_SumValue < _K && *_EndIndex <= SequenceLast)
	{
		*_EndIndex += 1;
		*_SumValue += _Sequence[*_EndIndex];
		
	}
	//*_EndIndex -= 1;
	if (*_SumValue == _K)
	{
		return true;
	}
	
	return false;
}

vector<int> solution(vector<int> sequence, int k) {
	vector<int> answer;

	vector<Sequence> Candidates_1;
	vector<Sequence> Candidates_2;
	int MostShortLength = -1; // -1일 경우 첫 번째 인덱스를 최솟값으로

	int SumValue = sequence[0];

	int EndIndex = 0;
	int SquenceEndIndex = sequence.size() - 1;
	bool bIsSubsequence = false;
	for (int i = 0; i < sequence.size(); ++i)
	{
		while (SumValue < k && EndIndex <= SquenceEndIndex)
		{
			EndIndex += 1;
			SumValue += sequence[EndIndex];

		}
		//*_EndIndex -= 1;
		if (SumValue == k)
		{
			bIsSubsequence = true;
		}
		else
		{
			bIsSubsequence = false;

		}
		if (bIsSubsequence == true)
		{
			Sequence NewSequence;
			NewSequence.StartIndex = i;
			NewSequence.EndIndex = EndIndex;
			if (MostShortLength == -1)
			{
				MostShortLength = NewSequence.GetLength();
			}
			if (NewSequence.GetLength() < MostShortLength)
			{
				MostShortLength = NewSequence.GetLength();
			}
			Candidates_1.push_back(NewSequence);
		}
		SumValue -= sequence[i];
	}

	if (Candidates_1.size() == 1)
	{
		answer.push_back(Candidates_1[0].StartIndex);
		answer.push_back(Candidates_1[0].EndIndex);
		return answer;
	}

	for (int i = 0; i < Candidates_1.size(); ++i)
	{
		if (Candidates_1[i].GetLength() != MostShortLength)
		{
			continue;
		}

		Candidates_2.push_back(Candidates_1[i]);
	}

	if (Candidates_2.empty() == true)
	{
		answer.push_back(Candidates_1[0].StartIndex);
		answer.push_back(Candidates_1[0].EndIndex);
		return answer;
	}
	answer.push_back(Candidates_2[0].StartIndex);
	answer.push_back(Candidates_2[0].EndIndex);
	return answer;
}

int main()
{
	solution({ 1, 1, 1, 2, 3, 4, 5 }, 5);
}


