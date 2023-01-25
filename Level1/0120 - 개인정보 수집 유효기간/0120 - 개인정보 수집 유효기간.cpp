#include <string>
#include <vector>

#include <sstream>
#include <map>

using namespace std;

std::vector<std::string> Split(std::string_view _StringData, char _Delimter)
{
	string Data = _StringData.data();
	string token;

	stringstream streamData;
	streamData.str(Data);

	std::vector<std::string> SplitData;

	while (getline(streamData, token, _Delimter))
	{
		SplitData.push_back(token);
	}
	return SplitData;
}

class Privacy
{
public:
	static void SetToday(std::string_view _Today)
	{
		TodayData = Split(_Today, '.');
	}
	void SetAgreeDate(std::string_view _Date)
	{
		AgreeDate_ = Split(_Date, '.');
	}
	bool IsExpired()
	{
		//차가 Term의 값보다 커야함
		int Difference = GetDay(TodayData) - GetDay(AgreeDate_);

		int TermInt = Terms[Term_] * 28;
		if (Difference >= TermInt)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int GetDay(std::vector<std::string> _Date)
	{
		int YearInt = stoi(_Date[0]) * 12 * 28;
		int MonthInt = stoi(_Date[1]) * 28;
		int DayInt = stoi(_Date[2]);

		return (YearInt + MonthInt + DayInt);
	}

	std::vector<std::string> AgreeDate_; //약관 동의한 날짜

	std::string Term_ = "";

	static std::map< std::string, int> Terms;
	static std::vector<std::string> TodayData;
};

std::map< std::string, int> Privacy::Terms;
std::vector<std::string> Privacy::TodayData;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer;
	std::vector<Privacy> Data;

	//파싱 & 데이터 저장
	{
		//약관 종류 파싱
		for (int i = 0; i < terms.size(); i++)
		{
			std::vector<std::string> TermSplitData;

			TermSplitData = Split(terms[i], ' ');
			Privacy::Terms.insert(std::make_pair(TermSplitData[0], std::stoi(TermSplitData[1])));
		}

		//Today 파싱
		Privacy::SetToday(today);

		//개인정보 파싱
		for (int i = 0; i < privacies.size(); i++)
		{
			Privacy p;

			std::vector<std::string> SplitData = Split(privacies[i], ' ');

			std::string Term = SplitData[1];
			std::string Day = SplitData[0];

			p.SetAgreeDate(Day);
			p.Term_ = Term;

			Data.push_back(p);
		}
	}

	for (int i = 0; i < Data.size(); i++)
	{
		if (Data[i].IsExpired() == true)
		{
			answer.push_back(i + 1);
		}
	}

	return answer;
}
int main()
{
	solution("2022.05.19", { "A 6", "B 12", "C 3" }, { "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" , "2021.05.02 A", });
}