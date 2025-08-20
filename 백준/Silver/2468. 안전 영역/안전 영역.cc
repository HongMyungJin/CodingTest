#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N;
vector<vector<bool>> visited;
vector<vector<int>> adj;

void DFS(int i, int j, int height)
{
	if (visited[i][j])
		return;
	visited[i][j] = true;

	if (i + 1 < N && adj[i + 1][j] >= height)
	{
		DFS(i + 1, j, height);
	}
	if (i - 1 >= 0 && adj[i - 1][j] >= height)
	{
		DFS(i - 1, j, height);
	}
	if (j + 1 < N && adj[i][j + 1] >= height)
	{
		DFS(i, j + 1, height);
	}
	if (j - 1 >= 0 && adj[i][j - 1] >= height)
	{
		DFS(i, j - 1, height);
	}
}

int AllDFS(int height)
{
	int areaN = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j] && adj[i][j] >= height)
			{
				DFS(i, j, height);
				areaN++;
			}
		}
	}
	return areaN;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	adj = vector<vector<int>>(N, vector<int>(N, false));
	int input;
	int maxArea = INT_MIN;
	int maxHeight = INT_MIN;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> input;
			adj[i][j] = input;
			maxHeight = max(adj[i][j], maxHeight);
		}
		
	}

	for (int i = 0; i <= maxHeight; i++)
	{
		visited = vector<vector<bool>>(N, vector<bool>(N, false));
		maxArea = max(AllDFS(i), maxArea);
	}
	

	cout << maxArea;
	return 0;
}