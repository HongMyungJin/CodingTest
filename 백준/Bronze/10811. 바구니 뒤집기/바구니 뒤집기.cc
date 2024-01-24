#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N, ChangeN, i, j;
	std::cin >> N >> ChangeN;

	std::vector<int> nums(N);
	for (int t = 0; t < nums.size(); t++)
		nums[t] = t;

	for (int t = 0; t < ChangeN; t++)
	{
		std::cin >> i >> j;
		std::reverse(nums.begin() + i - 1, nums.begin() + j);
	}
	
	for (int t = 0; t < nums.size(); t++)
		std::cout << nums[t] + 1 << " ";
}