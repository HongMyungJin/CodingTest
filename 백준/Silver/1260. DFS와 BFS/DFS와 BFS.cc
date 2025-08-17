#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, V;
vector<bool> visitedDFS(false);
vector<bool> visitedBFS(false);

vector<vector<int>> adjacency;

void DFS(int n)
{
	visitedDFS[n] = true;
	cout << n + 1 << " ";
	for (int i = 0; i < N; i++)
		if (!visitedDFS[i] && adjacency[n][i] == 1)
		{
			DFS(i);
		}
}

void BFS(int n)
{
	visitedBFS[n] = true;
	queue<int> q;
	q.push(n);
	while (!q.empty())
	{
		int front = q.front();
		q.pop();

		cout << front + 1 << " ";
		for (int i = 0; i < N; i++)
		{
			if (!visitedBFS[i] && adjacency[front][i] == 1)
			{
				q.push(i);
				visitedBFS[i] = true;
			}
		}
		
	}
}

int main()
{
	cin >> N >> M >> V;

	adjacency = vector<vector<int>>(N);

	for (int i = 0; i < N; i++)
	{
		adjacency[i].resize(N);
	}
	visitedDFS.resize(N);
	visitedBFS.resize(N);

	int from, to;
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to;

		adjacency[from - 1][to - 1] = 1;
		adjacency[to - 1][from - 1] = 1;
	}

	DFS(V - 1);
	cout << '\n';
	BFS(V - 1);
	return 0;
}