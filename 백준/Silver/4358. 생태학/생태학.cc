#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	map<string, int> datas;
	string data;

	while (getline(cin, data, '\n'))
	{
		datas[data]++;
		n++;
	}

	cout << fixed;
	cout.precision(4);
	for (auto& value : datas)
	{
		cout << value.first << " " << (((float)value.second / n) * 100) << '\n';
	}
	return 0;
}