#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	vector<int> inputs;
	cin >> n;
	inputs.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> inputs[i];
	}

	int max = *max_element(inputs.begin(), inputs.end());

	vector<pair<int, int>> dp;

	dp.resize(max + 3);

	dp[0] = { 1, 0 };
	dp[1] = { 0, 1 };

	for (int i = 2; i < max + 1; i++)
	{
		dp[i].first = dp[i - 1].first + dp[i - 2].first;
		dp[i].second = dp[i - 1].second + dp[i - 2].second;
	}

	for (int i = 0; i < inputs.size(); i++)
	{
		cout << dp[inputs[i]].first << " " << dp[inputs[i]].second << endl;
	}
}