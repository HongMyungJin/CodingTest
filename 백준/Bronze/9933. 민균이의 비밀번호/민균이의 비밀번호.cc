#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int N;
	string passWord;
	map<string, int> values;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> passWord;
		++values[passWord];
		reverse(passWord.begin(), passWord.end());
		++values[passWord];
	}

	for (auto& value : values)
	{
		if (value.second >= 2)
		{
			string passWordData = value.first;
			int length = passWordData.length();
			cout << length << " " << passWordData[length / 2];
			break;
		}
	}
	return 0;
}