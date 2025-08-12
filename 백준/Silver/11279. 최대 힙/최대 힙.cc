#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int input;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (0 == input)
		{
			if (pq.empty())
			{
				cout << 0 << '\n';
				continue;
			}
			cout << pq.top() << '\n';
			pq.pop();
		}
		else
		{
			pq.push(input);
		}
	}
}