#include <iostream>
#include <vector>
using namespace std;

int w, h;

int dx[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, 1, -1 };
vector<vector<int>> dfs;
vector<vector<bool>> visited;
void DFS(int i, int j)
{
	visited[i][j] = true;
	for (int t = 0; t < 8; t++) // 4방향
	{
		int x = i + dx[t]; // 행
		int y = j + dy[t]; // 열
		if (x < 0 || x >= h || y < 0 || y >= w)
			continue;
		if (!visited[x][y] && 1 == dfs[x][y])
		{
			DFS(x, y);
		}
	}
}

int AllDFS()
{
	int n = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (!visited[i][j] && 1 == dfs[i][j])
			{
				DFS(i, j);
				n++;
			}
		}
	}
	return n;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		dfs = vector<vector<int>>(h, vector<int>(w));
		visited = vector<vector<bool>>(h, vector<bool>(w, false));

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> dfs[i][j];
			}
		}

		cout << AllDFS() << '\n';
	}


	return 0;
}