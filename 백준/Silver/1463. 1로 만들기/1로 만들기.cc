#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 2일 경우 -> 1
// 
// 3일 경우 -> 1
// 
// 4일 경우  -> 2
// (4 - 1) + 3일 경우
// (4 / 2) + 2일 경우
// 5일 경우 -> 3
// (5 - 1) + 4일 경우
// 
// 6일 경우 -> 
// (6 / 2) + 3일 경우
// (6 / 3) + 2일 경우
//
// 7일 경우
// (7 - 1) + 6일 경우
// 
// f(n) = 3개 중에 되는 연산 해보고 가장 횟수 적은 거
int main()
{
	int n;
	cin >> n;

	vector<int> values;
	values.resize(n + 3);

	values[2] = 1;
	values[3] = 1;
	for (int i = 4; i < n + 1; i++)
	{
		int min = INT_MAX;
		if (i % 2 == 0)
		{
			if (min > values[i / 2])
				min = values[i / 2];
		}
		if (i % 3 == 0)
		{
			if (min > values[i / 3])
				min = values[i / 3];
		}
		if (min > values[i - 1])
			min = values[i - 1];

		values[i] = min + 1;
	}

	cout << values[n];
}