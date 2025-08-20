#include <iostream>
#include <vector>
using namespace std;

int N;
vector<bool> visited;
vector<int> parents;
vector<vector<int>> adj;

void DFS(int n)
{
	if (visited[n])
		return;

	visited[n] = true;
	for (int i = 0; i < adj[n].size(); i++)
	{
		int adjValue = adj[n][i];
		if (!visited[adjValue])
		{
			parents[adjValue] = n;
			DFS(adjValue);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	visited = vector<bool>(N, false);
	parents = vector<int>(N, -1);
	adj = vector<vector<int>>(N, vector<int>());
	int input[2];
	for (int i = 0; i < N - 1; i++)
	{
		cin >> input[0] >> input[1];
		adj[input[0] - 1].emplace_back(input[1] - 1);
		adj[input[1] - 1].emplace_back(input[0] - 1);
	}

	DFS(0);
	for (int i = 1; i < parents.size(); i++)
	{
		cout << parents[i] + 1 << '\n';
	}
	return 0;
}