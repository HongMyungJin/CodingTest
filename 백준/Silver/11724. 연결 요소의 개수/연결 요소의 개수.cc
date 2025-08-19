#include <iostream>
#include <vector>
using namespace std;

int N, M;

vector<vector<int>> adj;
vector<bool> visited;

void DFS(int n, int& connetN)
{
	if (visited[n])
		return;
	visited[n] = true;
	connetN++;

	for (int i = 0; i < N; i++)
	{
		if (adj[n][i] && !visited[i])
			DFS(i, connetN);
	}
}

void AllDFS()
{
	int allConnetN = 0;
	for (int i = 0; i < N; i++)
	{
		int connetN = 0;
		if (!visited[i])
			DFS(i, connetN);
		if (connetN > 0)
			allConnetN++;
	}

	cout << allConnetN;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;


	int input[2];
	adj = vector<vector<int>>(N, vector<int>(N, 0));
	visited = vector<bool>(N, false);
	for (int i = 0; i < M; i++)
	{
		cin >> input[0] >> input[1];
		adj[input[0] - 1][input[1] - 1] = 1;
		adj[input[1] - 1][input[0] - 1] = 1;
	}

	AllDFS();

	return 0;
}