#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	int input;
	int max = -2100000000;
	cin >> N >> K;

	vector<int> prefix(N + 1, 0);
	for (int i = 1; i < N + 1; i++)
	{
		cin >> input;
		prefix[i] = prefix[i - 1] + input;

		if (i >= K)
		{
			int cur = prefix[i] - prefix[i - K];
			max = max > cur ? max : cur;
		}
	}

	cout << max;
}