#include <iostream>
#include <map>
using namespace std;

int main()
{
	int N;
	char game;
	map<string, int> values;
	cin >> N >> game;

	int gameN = game == 'Y' ? 2 : (game == 'F' ? 3 : 4);

	string name;

	int playN = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> name;
		if (values.count(name) == 0)
		{
			++playN;
		}
		++values[name];
	}

	cout << playN / (gameN - 1);

	return 0;
}