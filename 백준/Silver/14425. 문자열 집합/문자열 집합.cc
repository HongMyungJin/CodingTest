#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;

	cin >> N >> M;

	int totalN = 0;
	unordered_set<string> sets;
	string input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		sets.insert(input);
	}

	for (int j = 0; j < M; j++)
	{
		cin >> input;
		
		if (sets.find(input) != sets.end())
		{
			totalN++;
		}
	}

	cout << totalN;
}