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
	string name;
	map<string, int> values;
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> name;
		++values[name];
	}

	int max = INT_MIN;
	string maxName;
	for (const auto& value : values)
	{
		if (max < value.second)
		{
			max = value.second;
			maxName = value.first;
		}
	}
	cout << maxName;
	return 0;
}