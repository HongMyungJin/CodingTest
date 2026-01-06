#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	
	vector<int> subSum(N + 1, 0);
	int input;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> input;
		subSum[i] = subSum[i - 1] + input;
	}

	int first, last;
	for (int i = 0; i < M; i++)
	{
		cin >> first >> last;
		cout << subSum[last] - subSum[first - 1] << '\n';
	}
}