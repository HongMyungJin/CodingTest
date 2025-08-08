#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b;
	int input;

	vector<int> saveValues;

	cin >> a >> b;

	map<int, bool> values;

	for (int i = 0; i < a; i++)
	{
		cin >> input;
		values[input] = true;
	}

	for (int i = 0; i < b; i++)
	{
		cin >> input;
		if(values[input] == true)
			values[input] = false;
	}

	for (auto& value : values)
	{
		if (value.second)
		{
			saveValues.emplace_back(value.first);
		}
	}

	cout << saveValues.size() << "\n";
	for (int& value : saveValues)
	{
		cout << value << " ";
	}

	return 0;
}