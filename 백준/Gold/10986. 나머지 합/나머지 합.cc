#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;

	cin >> N >> M;

	vector<long long> prefixs(N + 1, 0);
	map<int, int> prefixN;
	int n;
	for (int i = 1; i < prefixs.size(); i++)
	{
		cin >> n;
		prefixs[i] = prefixs[i - 1] + n;
	}

	for (int i = 0; i < prefixs.size(); i++)
	{
		prefixs[i] %= M;

		int value = prefixs[i];

		if (prefixN.find(value) == prefixN.end())
		{
			prefixN.insert({ value, 1 });

		}
		else
		{
			++prefixN[value];
		}
	}

	long long total = 0;

	for (pair<int, int> value : prefixN)
	{
		total += (long long)value.second * (value.second - 1) / 2;
	}

	cout << total;
}