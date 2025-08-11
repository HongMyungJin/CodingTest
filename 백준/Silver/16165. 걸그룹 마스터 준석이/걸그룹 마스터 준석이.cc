#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int N, M;
	map<string, vector<string>> values;
	map<string, string> members;
	cin >> N >> M;

	string teamName;
	int teamN;
	string memberName;

	for (int i = 0; i < N; i++)
	{
		cin >> teamName >> teamN;
		values[teamName].resize(teamN);
		for (int j = 0; j < teamN; j++)
		{
			cin >> memberName;
			values[teamName][j] = memberName;
			members[memberName] = teamName;
		}
		sort(values[teamName].begin(), values[teamName].end());
	}

	int quiz;
	string name;
	for (int i = 0; i < M; i++)
	{
		cin >> name >> quiz;
		if (quiz == 0)
		{
			for (auto& value : values[name])
				cout << value << '\n';
		}
		else
		{
			cout << members[name] << '\n';
		}

	}

	return 0;
}