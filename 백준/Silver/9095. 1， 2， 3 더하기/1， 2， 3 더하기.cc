#include <iostream>
#include <array>
using namespace std;

int main()
{
	int testN;
	cin >> testN;

	array<int, 12> dp;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	/*
	4 = 1 + 3
		2 + 2
		3 + 1
	5 = 2 + 3
	  = 3 + 2
	  = 4 + 1
	*/
	for (int i = 4; i < 12; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	int n;
	for (int i = 0; i < testN; i++)
	{
		cin >> n;
		cout << dp[n] << '\n';
	}
}