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
		cin >> input;
		pq.push(input);
	}

	long long sum = 0;
	if (n == 1)
	{
		cout << 0 << '\n';
	}
	else
	{
		while (true)
		{
			int top = 0;
			if (pq.size() >= 2)
			{
				for (int i = 0; i < 2; i++)
				{
					top += pq.top();
					pq.pop();
				}
				sum += top;
				if (pq.empty())
					break;
				pq.push(top);
			}	
			
		}

		cout << sum;
	}
}