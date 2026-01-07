#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q, l, r;
	char a;
	string s;
	cin >> s >> q;
	vector<map<char, int>> prefixs(s.length() + 1);

	for (int i = 1; i < prefixs.size(); i++)
	{
		char ch = s[i - 1];

		prefixs[i] = prefixs[i - 1];
		++prefixs[i][ch];
	}

	for (int i = 0; i < q; i++)
	{
		cin >> a >> l >> r;

		int right = 0;
		int left = 0;
		if (prefixs[r + 1].find(a) != prefixs[r + 1].end())
		{
			right = prefixs[r + 1][a];
		}

		if (prefixs[l].find(a) != prefixs[l].end())
		{
			left = prefixs[l][a];
		}

		cout << right - left << '\n';
	}
}