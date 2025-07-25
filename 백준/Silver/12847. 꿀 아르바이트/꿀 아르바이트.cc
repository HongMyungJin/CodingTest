#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> values;
	values.resize(n);

	long windowSum = 0;
	long maxValue = LONG_MIN;
	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
		windowSum += values[i];
		if (i >= m - 1)
		{
			maxValue = max(maxValue, windowSum);
			windowSum -= values[i - (m - 1)];
		}
	}
	cout << maxValue;
}