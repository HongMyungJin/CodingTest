#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	priority_queue<int> pq;
	cin >> n;

	int a;
	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a == 0)
		{
			if (!pq.empty())
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
			else
			{
				cout << -1 << '\n';
			}
		}
		else
		{
			for (int j = 0; j < a; j++)
			{
				cin >> input;
				pq.push(input);
			}
		}
	}
	return 0;
}