#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;

	cin >> N >> M;

	int totalN = 0;
	unordered_map<string, int> sets;
	string input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		++sets[input];
	}

	for (int j = 0; j < M; j++)
	{
		cin >> input;
		totalN += sets[input];
	}

	cout << totalN;
}