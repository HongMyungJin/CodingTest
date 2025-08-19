#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<char>> dfs;
vector<vector<bool>> visited;

void DFS(int x, int y, char value, int& n, bool isBlind = false)
{
	if (visited[x][y])
		return;

	visited[x][y] = true;
	if (x - 1 >= 0 && !visited[x - 1][y])
	{
		if (dfs[x - 1][y] == value)
		{
			DFS(x - 1, y, value, n, isBlind);
		}
		else
		{
			if (isBlind && (dfs[x - 1][y] == 'R' || dfs[x - 1][y] == 'G') && (value == 'R' || value == 'G'))
			{
				DFS(x - 1, y, value, n, isBlind);
			}
		}
	}
	if (x + 1 < N &&  !visited[x + 1][y])
	{
		if (dfs[x + 1][y] == value)
		{
			DFS(x + 1, y, value, n, isBlind);
		}
		else
		{
			if (isBlind && (dfs[x + 1][y] == 'R' || dfs[x + 1][y] == 'G') && (value == 'R' || value == 'G'))
			{
				DFS(x + 1, y, value, n, isBlind);
			}
		}
	}
	if (y - 1 >= 0 && !visited[x][y - 1])
	{
		if (dfs[x][y - 1] == value)
		{
			DFS(x, y - 1, value, n, isBlind);
		}
		else
		{
			if (isBlind && (dfs[x][y - 1] == 'R' || dfs[x][y - 1] == 'G') && (value == 'R' || value == 'G'))
			{
				DFS(x, y - 1, value, n, isBlind);
			}
		}
	}
	if (y + 1 < N && !visited[x][y + 1])
	{
		if (dfs[x][y + 1] == value)
		{
			DFS(x, y + 1, value, n, isBlind);
		}
		else
		{
			if (isBlind && (dfs[x][y + 1] == 'R' || dfs[x][y + 1] == 'G') && (value == 'R' || value == 'G'))
			{
				DFS(x, y + 1, value, n, isBlind);
			}
		}
	}
	n++;
}

void AllDFS(bool blind)
{
	int zone = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int n = 0;
			DFS(i, j, dfs[i][j], n, blind);
			if (n > 0)
				zone++;
		}
	}

	cout << zone << ' ';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	char input;
	dfs = vector<vector<char>>(N, vector<char>(N, ' '));
	visited = vector<vector<bool>>(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> input;
			dfs[i][j] = input;
		}
	}
	
	AllDFS(false);
	visited.clear();
	visited = vector<vector<bool>>(N, vector<bool>(N, false));

	AllDFS(true);
	return 0;
}