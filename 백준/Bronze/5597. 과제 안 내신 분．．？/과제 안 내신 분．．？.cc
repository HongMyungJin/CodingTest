#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	vector<bool> nums(30, false);
	int num;
	for (int i = 0; i < 28; i++)
	{
		cin >> num;
		nums[num - 1] = true;
	}

	for (int t = 0; t < 30; t++)
	{
		if(!nums[t])
			cout << t + 1 << endl;
	}
}