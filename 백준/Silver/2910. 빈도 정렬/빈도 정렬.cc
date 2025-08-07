#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b)
{
	if (a.second.second > b.second.second)
		return true;
	else if (a.second.second == b.second.second)
	{
		return a.second.first < b.second.first;
	}
	else
		return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<int, pair<int, int>> values;


	int N, C;

	cin >> N >> C;

	int index = 0;
	for (int i = 0; i < N; i++)
	{
		int data;

		cin >> data;
		if (values.count(data) == 0)
			values[data].first = index++;
		values[data].second++;
	}

	vector<pair<int, pair<int, int>>> valuesVec(values.begin(), values.end());
	sort(valuesVec.begin(), valuesVec.end(), cmp);

	for (auto& value : valuesVec)
	{
		for (int i = 0; i < value.second.second; i++)
			cout << value.first << " ";
	}
	return 0;
}