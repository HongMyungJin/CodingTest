#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 반복문
bool binary_search(int m, vector<int>& nums)
{
	int start = 0;
	int end = nums.size() - 1;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		// m이랑 같다면
		if (nums[mid] == m)
		{
			return true;
		} // 크다면
		else if (nums[mid] < m)
		{
			start = mid + 1;
		} // 작다면
		else
		{
			end = mid - 1;
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N;
	vector<int> nums(N);

	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
	// 이분탐색 위한 정렬
	sort(nums.begin(), nums.end());

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> num;

		if (binary_search(num, nums))
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}
}