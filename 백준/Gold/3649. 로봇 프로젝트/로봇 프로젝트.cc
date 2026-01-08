#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, n;
	while (cin >> x >> n)
	{
		vector<int> values(n);

		x *= 10000000;

		for (int i = 0; i < n; i++)
		{
			cin >> values[i];
		}

		sort(values.begin(), values.end());

		int left = 0;
		int right = n - 1;

		while (left < right)
		{
			int sum = values[left] + values[right];

			if (sum < x)
			{
				++left;
			}
			else if (sum > x)
			{
				--right;
			}
			else
			{
				cout << "yes " << values[left] << " " << values[right] << '\n';
				break;
			}
		}

		if (left >= right)
		{
			cout << "danger" << '\n';
		}
	}
}