#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;

	int num;
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());

	cin >> M;
	for (int j = 0; j < M; j++)
	{
		cin >> num;
		cout << upper_bound(nums.begin(), nums.end(), num) - lower_bound(nums.begin(), nums.end(), num) << ' ';
	}
}