#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n; // testCaseN
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		////////////// Input //////////////
		vector<pair<int, int>> callValues;
		int documentN, index = 0;
		cin >> documentN >> index;

		for (int j = 0; j < documentN; j++)
		{
			int priority = 0;
			cin >> priority;
			callValues.emplace_back(make_pair(j, priority));
		}
		
		////////////// test //////////////
		pair<int, int> findData;;
		int printN = 0;
		while (true)
		{
			auto maxValue = max_element(callValues.begin(), callValues.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second;});
			findData = callValues.front();

			if ((*maxValue).second > findData.second) // 중요도가 낮으면
			{
				callValues.emplace_back(callValues.front()); // 뒤로
			}
			else // 중요도가 높을 경우
			{
				printN++;
				if (findData.first == index) // 값을 찾을 경우
					break;
			}
			callValues.erase(callValues.begin());// 기존 앞에 있던 것 지우기
		}

		cout << printN << "\n";
	}
	return 0;
}