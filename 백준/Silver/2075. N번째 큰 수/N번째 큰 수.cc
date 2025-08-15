#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n, input;

	cin >> n;

	priority_queue<int, vector<int>, greater<>> pq;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> input;
			pq.push(input);

			if (pq.size() == n + 1)
			{
				pq.pop();
			}
		}
	}

	cout << pq.top();
	return 0;
}