#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
	int row;
	int col;

	int n;

	Node(int row, int col, int n) : row(row), col(col), n(n)
	{

	}
};
int M, N;
vector<vector<int>> board;

int dirX[4] = { -1, 1, 0, 0 };
int dirY[4] = {0, 0 , -1, 1};
int BFS()
{
	int n = 0;
	queue<Node> q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (1 == board[i][j])
				q.push(Node(i, j, 0));
		}
	}
	
	while (!q.empty())
	{
		Node node = q.front();
		q.pop();

		for (int t = 0; t < 4; t++)
		{
			int row = node.row + dirX[t];
			int col = node.col + dirY[t];

			if (row >= N || col >= M || row < 0 || col < 0)
				continue;

			if (0 == board[row][col])
			{
				board[row][col] = 1;
				q.push(Node(row, col, node.n + 1));
			}

		}

		if (q.empty())
		{
			return node.n;
		}
		
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	board = vector<vector<int>>(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

	int root = BFS();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
		}
	}

	cout << root;
	
	return 0;
}