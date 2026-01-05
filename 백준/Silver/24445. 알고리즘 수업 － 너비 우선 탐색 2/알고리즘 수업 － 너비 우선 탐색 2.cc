#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, R;

void BFS(vector<vector<int>>& adjs, vector<int>& visited)
{
	int idx = 0;
	queue<int> q;
	q.push(R);
	while (!q.empty())
	{
		int back = q.front();
		q.pop();

		if (visited[back] == 0)
		{
			visited[back] = ++idx;
		}
		else
		{
			continue;
		}
		for (int i = 0; i < adjs[back].size(); i++)
		{
			int next = adjs[back][i];
			if(visited[next] == 0)
			{
				q.push(next);
			}
		}
	}
}

int main()
{
	cin >> N >> M >> R;

	vector<vector<int>> adjs(N + 1);
	vector<int> visited(N + 1, 0);

	int u, v;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		adjs[u].push_back(v);
		adjs[v].push_back(u);
	}

	for (int i = 0; i < N + 1; i++)
	{
		sort(adjs[i].begin(), adjs[i].end(), greater<int>());
	}

	BFS(adjs, visited);

	for (int i = 1; i < N + 1; i++)
	{
		cout << visited[i] << '\n';
	}
}