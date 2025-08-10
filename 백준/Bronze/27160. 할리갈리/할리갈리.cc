#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	map<string, int> datas;
	cin >> N;

	string data;
	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> data >> n;
		datas[data] += n;
	}

	string answer = "NO";
	for (auto& value : datas)
	{
		if (value.second == 5)
		{
			answer = "YES";
			break;
		}
	}
	cout << answer;
	return 0;
}