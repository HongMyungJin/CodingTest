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
	string data;

	cin >> N;

	map<string, int> values;
	for (int i = 0; i < N; i++)
	{
		cin >> data;
		values[data.substr(data.find(".") + 1, data.length() - 1)]++;
	}

	for (auto& value : values)
		cout << value.first << " " << value.second << '\n';
	return 0;
}