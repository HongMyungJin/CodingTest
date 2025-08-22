#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

vector<vector<int>> bfs;
vector<vector<bool>> visited;
vector<vector<int>> dist;
int dirRow[4] = { -1, 1, 0, 0 };
int dirCol[4] = { 0, 0, -1, 1 };
int N, M;

int BFS(int i, int j)
{
	queue<pair<int, int>> q;
	pair<int, int> top = make_pair(i, j);
	q.push(make_pair(i, j));
	visited[i][j] = true;
	dist[i][j] = 1;
	while (!q.empty())
	{
		top = q.front();
		q.pop();

		if (top.first == N - 1 && top.second == M - 1)
			return dist[top.first][top.second];

		for (int t = 0; t < 4; t++)
		{
			int row = dirRow[t] + top.first;
			int col = dirCol[t] + top.second;

			if (row >= N || row < 0 || col >= M || col < 0)
				continue;
			if (1 == bfs[row][col] && !visited[row][col])
			{
				visited[row][col] = true;
				dist[row][col] = dist[top.first][top.second] + 1;
				q.push(make_pair(row, col));
			}
		}
	}

	return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	bfs = vector<vector<int>>(N, vector<int>(M));
	visited = vector<vector<bool>>(N, vector<bool>(M, false));
	dist = vector<vector<int>>(N, vector<int>(M, 0));

	string input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		for (int j = 0; j < M; j++)
		{
			bfs[i][j] = input[j] - '0';
		}
	}

	cout << BFS(0, 0);
	return 0;
}