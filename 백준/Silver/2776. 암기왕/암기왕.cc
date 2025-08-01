#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, M;
	int data;

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		map<int, int> values;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> data;
			++values[data];
		}

		cin >> M;
		for (int i = 0; i < M; i++)
		{
			cin >> data;
			if (values.count(data) == 0)
				cout << 0 << '\n';
			else
				cout << 1 << '\n';
		}
	}

	return 0;
}