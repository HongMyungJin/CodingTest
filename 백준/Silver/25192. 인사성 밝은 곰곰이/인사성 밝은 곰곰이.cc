#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int count = 0;
	unordered_map<string, int> maps;
	cin >> n;

	string input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;

		if (input == "ENTER")
		{
			maps.clear();
		}
		else
		{
			if (maps.find(input) == maps.end())
			{
				maps.insert(make_pair(input, 1));
				count++;
			}

		}
	}

	cout << count;
	return 0;
}