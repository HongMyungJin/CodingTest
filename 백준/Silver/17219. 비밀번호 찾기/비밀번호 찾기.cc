#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	unordered_map<string, string> maps;

	cin >> n >> m;

	string site, password;
	for (int i = 0; i < n; i++)
	{
		cin >> site >> password;
		maps[site] = password;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> site;
		cout << maps[site] << '\n';
	}

	return 0;
}