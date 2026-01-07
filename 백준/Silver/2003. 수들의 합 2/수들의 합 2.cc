#include <iostream>
#include <vector>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;

	cin >> N >> M;

	int n;
	vector<int> nums(N);
	for (int i = 0; i < nums.size(); i++)
	{
		cin >> nums[i];
	}

	int start = 0;
	int end = 0;

	int subSum = 0;
	int subSumN = 0;
	while (true)
	{
		if (M < subSum)
		{
			subSum -= nums[start];
			start++;
		}
		else
		{
			if (end >= nums.size())
			{
				break;
			}
			subSum += nums[end];
			end++;
		}

		if (subSum == M)
		{
			subSumN++;
		}

	}

	cout << subSumN;
}