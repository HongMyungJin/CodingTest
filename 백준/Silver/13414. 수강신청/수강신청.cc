#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<string, pair<int, int>> A, pair<string, pair<int, int>> B)
{
	return A.second.first < B.second.first;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K, L;
	string data;

	cin >> K >> L;

	map<string, pair<int, int>> datas;

	int idx = 0;
	for (int i = 0; i < L; i++)
	{
		cin >> data;

		datas[data].first = idx++;
	}
	
	vector<pair<string, pair<int, int>>> vecDatas(datas.begin(), datas.end());
	sort(vecDatas.begin(), vecDatas.end(), cmp);


	for (auto& value : vecDatas)
	{
		cout << value.first << '\n';
		if (--K <= 0)
			break;
	}

	return 0;
}