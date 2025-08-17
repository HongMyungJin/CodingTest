#include <iostream>
#include <vector>
using namespace std;

int N, M, ComputerN;
vector<bool> visitedDFS(false);

vector<vector<int>> adjacency;

void DFS(int n)
{
	visitedDFS[n] = true;
	ComputerN++;
	for (int i = 0; i < N; i++)
		if (!visitedDFS[i] && adjacency[n][i] == 1)
		{
			DFS(i);
		}
}


int main()
{
	ComputerN = 0;
	cin >> N >> M;

	adjacency = vector<vector<int>>(N);

	for (int i = 0; i < N; i++)
	{
		adjacency[i].resize(N);
	}
	visitedDFS.resize(N);

	int from, to;
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to;

		adjacency[from - 1][to - 1] = 1;
		adjacency[to - 1][from - 1] = 1;
	}

	DFS(0);

	cout << ComputerN - 1;
	return 0;
}