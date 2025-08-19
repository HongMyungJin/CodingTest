#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> visitedDFS;
vector<vector<int>> VertexDFS;

int T, M, N, K;

void DFS(int x, int y, int& n)
{
	if (visitedDFS[x][y] || !VertexDFS[x][y])
		return;
	visitedDFS[x][y] = true;
	if (x - 1 >= 0 && VertexDFS[x - 1][y] && !visitedDFS[x - 1][y]) // 왼쪽
	{
		DFS(x - 1, y, n);
	}
	if (x + 1 < M && VertexDFS[x + 1][y] && !visitedDFS[x + 1][y]) // 오른쪽
	{
		DFS(x + 1, y, n);
	}
	if (y - 1 >= 0 && VertexDFS[x][y - 1] && !visitedDFS[x][y - 1]) // 위
	{
		DFS(x, y - 1, n);
	}
	if (y + 1 < N && VertexDFS[x][y + 1] && !visitedDFS[x][y + 1]) // 아래
	{
		DFS(x, y + 1, n);
	}
	n++;
}

void AllDFS(int& wormN)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int n = 0;
			if (!visitedDFS[i][j] && VertexDFS[i][j])
			{
				DFS(i, j, n);
				if (n > 0)
					wormN++;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> K;

		visitedDFS = vector<vector<bool>>(M, vector<bool>(N, false));
		VertexDFS = vector<vector<int>>(M, vector<int>(N, 0));
		int x, y;
		for (int t = 0; t < K; t++)
		{
			cin >> x >> y;
			VertexDFS[x][y] = 1;
		}
		int wormN = 0;
		AllDFS(wormN);
		cout << wormN << '\n';

		visitedDFS.clear();
		VertexDFS.clear();
	}
	return 0;
}