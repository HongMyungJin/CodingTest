#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int N, M;
	int swap1, swap2;
	vector<int> nums;

	cin >> N >> M;

	nums.resize(N);

	for (int i = 0; i < nums.size(); i++)
		nums[i] = i + 1;

	for (int i = 0; i < M; i++)
	{
		cin >> swap1 >> swap2;
		swap(nums[swap1 - 1], nums[swap2 - 1]);
	}

	for (int i : nums)
		cout << i << " ";
}