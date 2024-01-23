#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int N, M;
	int i, j, k;
	vector<int> nums;

	cin >> N >> M;
	nums.resize(N);
	for (int t = 0; t < M; t++)
	{
		cin >> i >> j >> k;
		for (int m = i - 1; m <= j - 1; m++)
			nums[m] = k;
	}
	for (int i : nums)
		cout << i << " ";
}