#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;

	cin >> N;
	vector<int> values(N);

	for (int i = 0; i < N; i++)
	{
		cin >> values[i];
	}

	sort(values.begin(), values.end());

	int left = 0;
	int right = N - 1;

	int total = 0;


	cin >> M;
	while (left < right)
	{
		int sum = values[left] + values[right];


		if (sum < M)
		{
			left++;
		}
		else if (sum > M)
		{
			right--;
		}
		else
		{
			total++;

			left++;
			right--;
		}
	}

	cout << total;
}