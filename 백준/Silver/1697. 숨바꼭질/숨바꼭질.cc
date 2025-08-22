#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxValue = 100000;
vector<int> visitedN = vector<int>(maxValue + 1, -1);
int N, K;

int BFS()
{
	queue<int> q;
	q.push(N);
	int n = 0;
	visitedN[N] = 0;
	while (!q.empty())
	{
		int front = q.front();
		q.pop();

		if (front == K)
			return visitedN[front];

		int move[3] = { front - 1, front + 1, front * 2 };
		for (int i = 0; i < 3; i++)
		{
			if (move[i] < 0 || move[i] > maxValue || visitedN[move[i]] != -1)
				continue;
			visitedN[move[i]] = visitedN[front] + 1;
			q.push(move[i]);
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;
	cout << BFS();
	return 0;
}