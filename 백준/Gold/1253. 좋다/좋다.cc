#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<long long> values;
	values.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}

	sort(values.begin(), values.end());

	int goodN = 0;
	for (int i = 0; i < values.size(); i++)
	{
		long long sum = values[i];

		int left = 0;
		int right = values.size() - 1;
		while (left < right)
		{
			if (left == i)
			{
				left++;
				continue;
			}
			if (right == i)
			{
				right--;
				continue;
			}
			long long curSum = values[left] + values[right];
			if (curSum < sum)
			{
				left++;
			}
			else if (curSum > sum)
			{
				right--;
			}
			else
			{
				goodN++;
				break;
			}
		}
	}
	cout << goodN;
	return 0;
}