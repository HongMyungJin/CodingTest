#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	string keyword;
	cin >> N >> M;

	int n = N;
	unordered_map<string, int> values;
	for (int i = 0; i < N; i++)
	{
		cin >> keyword;
		++values[keyword];
	}

	string words;
	for (int i = 0; i < M; i++)
	{
		cin >> words;

		int curIdx = 0;
		int startIdx = 0;
		string key;
		while (curIdx != string::npos)
		{
			curIdx = words.find(',', startIdx);
			if (curIdx == string::npos)
			{
				key = words.substr(startIdx);
			}
			else
			{
				key = words.substr(startIdx, curIdx - startIdx);

				startIdx = curIdx + 1;
			}
			if (values.count(key) != 0 && values[key] != -1)
			{
				values[key] = -1;
				--n;
			}
		}
		cout << n << '\n';
		
	}
	return 0;
}