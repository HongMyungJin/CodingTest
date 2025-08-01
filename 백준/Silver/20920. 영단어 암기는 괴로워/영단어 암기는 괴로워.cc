#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<string, int>& data0, const pair<string, int>& data1)
{
	if (data0.second == data1.second)
	{
		if (data0.first.length() == data1.first.length())
		{
			if (data0.first == data1.first)
				return true;
			else
				return data0.first < data1.first;
		}
		else
			return data0.first.length() > data1.first.length();
	}
	return data0.second > data1.second;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	map<string, int> values;

	string data;

	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> data;
		if (data.length() < M)
			continue;
		++values[data];
	}

	vector<pair<string, int>> vecValues(values.begin(), values.end());
	sort(vecValues.begin(), vecValues.end(), cmp);
	
	for (const auto& value : vecValues)
	{
		cout << value.first << '\n';
	}
	return 0;
}