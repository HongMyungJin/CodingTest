#include <iostream>
#include <vector>

using namespace std;

int N, M;
int main()
{
	cin >> N >> M;

	vector<vector<int>> inputs(N, vector<int>(M, 0));
	int input;
	for (int t = 0; t < 2; t++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> input;
				inputs[i][j] += input;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << inputs[i][j] << ' ';
		}
		cout << '\n';
	}
}