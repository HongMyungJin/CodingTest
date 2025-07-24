#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	vector<int> values;
	cin >> n >> m;

	values.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}

	int left = 0;
	int right = 0;

	int sum = 0;
	int count = 0;
	while (true)
	{
		if (sum > m) // 클 경우
		{
			sum -= values[left++];
		}
		else if (sum < m) // 작을 경우
		{
			if (right >= values.size())
				break;
			sum += values[right++];
		}

		if(sum == m)
		{
			count++;
			sum -= values[left++];
		}
	}

	cout << count;
	return 0;
}