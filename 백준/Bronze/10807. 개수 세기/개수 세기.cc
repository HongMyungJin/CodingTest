#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int N, SearchN = 0;
	vector<int> nums;

	cin >> N;
	nums.resize(N);

	for (int i = 0; i < N; i++)
		cin >> nums[i];

	cin >> SearchN;

	cout << count(nums.begin(), nums.end(), SearchN) << endl;
}