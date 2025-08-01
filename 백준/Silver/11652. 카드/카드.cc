#include <iostream>
#include <map>
#include <climits>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	long long data;
	map<long long, int> values;
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> data;
		++values[data];
	}

	int max = INT_MIN;
	long long maxInt = 0;
	for (const auto& value : values)
	{
		if (max < value.second)
		{
			max = value.second;
			maxInt = value.first;
		}
	}
	cout << maxInt;
	return 0;
}