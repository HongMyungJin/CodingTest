#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int diri[4] = { -1, 1, 0, 0 };
int dirj[4] = { 0, 0, -1, 1 };
int R, C;

vector<vector<char>> board;
int maxValue = INT_MIN;

void DFS(int i, int j, int mask, int n)
{
	maxValue = max(maxValue, n);

	int curBit = 1 << (board[i][j] - 'A');

	mask |= curBit;

	for (int t = 0; t < 4; t++)
	{
		int row = diri[t] + i;
		int col = dirj[t] + j;
		if (row >= R || row < 0 || col >= C || col < 0)
			continue;

		int nextBit = 1 << (board[row][col] - 'A');
		if (nextBit & mask) // 누적된 값이 있을 때
			continue;
		DFS(row, col, mask, n + 1); // 누적
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	board = vector<vector<char>>(R, vector<char>(C));
	
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cin >> board[i][j];
	}

	DFS(0, 0, 0, 1);

	cout << maxValue;
	return 0;
}