#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<bool>> visitedDFS(false);

vector<vector<int>> VertexDFS;

vector<int> Complex;

void DFS(int x, int y, int& n)
{
	if (visitedDFS[x][y] || !VertexDFS[x][y])
		return;
	visitedDFS[x][y] = true;
	if (x - 1 >= 0 && VertexDFS[x - 1][y] && !visitedDFS[x - 1][y]) // 왼쪽
	{
		DFS(x - 1, y, n);
	}
	if (x + 1 < N && VertexDFS[x + 1][y] && !visitedDFS[x + 1][y]) // 오른쪽
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

void AllDFS()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int n = 0;
			if (!visitedDFS[i][j] && VertexDFS[i][j])
			{
				DFS(i, j, n);
				if (n != 0)
					Complex.push_back(n);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	VertexDFS = vector<vector<int>>(N);
	visitedDFS = vector<vector<bool>>(N);

	for (int i = 0; i < N; i++)
	{
		VertexDFS[i].resize(N);
		visitedDFS[i].resize(N);
	}
	
	char input;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> input;
			VertexDFS[i][j] = input - '0';
		}
	}

	AllDFS();
	sort(Complex.begin(), Complex.end());

	cout << Complex.size() << '\n';
	for (int i = 0; i < Complex.size(); i++)
	{
		cout << Complex[i] << '\n';
	}
	return 0;
}