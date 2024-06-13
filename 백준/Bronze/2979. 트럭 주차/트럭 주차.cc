#include <iostream>
#include <array>
#include <map>
int main()
{
	std::array<int, 3> arrPrice{ 0, };
	std::array<std::array<int, 2>, 3> arrTime{ 0, };

	std::map<int, int> TimeDatas;

	for (int i = 0; i < 3; i++)
		std::cin >> arrPrice[i];

	for (int i = 0; i < 3; i++)
		for(int j = 0; j < 2; j++)
			std::cin >> arrTime[i][j];

	for (int i = 0; i < 3; i++)
		for (int j = arrTime[i][0]; j < arrTime[i][1]; j++)
		{
			std::map<int, int>::iterator it = TimeDatas.find(j);
			if (it == TimeDatas.end()) // 찾지 못했을 경우
				TimeDatas.insert(std::make_pair(j, 1));
			else
				++(it->second);
		}

	int Total = 0;
	for (std::pair<int, int> TimeData : TimeDatas)
	{
		Total += TimeData.second * arrPrice[TimeData.second - 1];
	}

	std::cout << Total << std::endl;
	return 0;
}