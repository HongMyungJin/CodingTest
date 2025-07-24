#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
	// 부분합을 구하고
	int n, s;
	vector<int> values;
	cin >> n >> s;

	values.resize(n + 1);

	int data;
	for (int i = 1; i < n + 1; i++)
	{
		cin >> data;
		values[i] = values[i - 1] + data; // 누적
	}
	// 1 ~ n + 1까지 사용

	// S 이상 되는 것 중에 가장 짧은 것
	int left = 0;
	int right = 0;

	int minSize = INT_MAX;
	int sum = 0;
	while (true)
	{
		if (s <= sum)
		{
			int size = right - left;
			minSize = min(size, minSize);

			if (left >= n)
				break;

			sum -= values[left + 1] - values[left];
			++left;
		}
		else if (s > sum)
		{
			if (right >= n)
				break;
			sum += values[right + 1] - values[right];
			++right;
		}
	}

	cout << (minSize == INT_MAX ? 0 : minSize);
	return 0;
}