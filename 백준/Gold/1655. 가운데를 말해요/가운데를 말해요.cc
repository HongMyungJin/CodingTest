#include <iostream>
#include <queue>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, input;
	priority_queue<int, vector<int>, less<>> pq_less;
	priority_queue<int, vector<int>, greater<>> pq_greater;
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input;

		// 사이즈가 같을 경우
		
		if (pq_less.size() == 0)
		{
			pq_less.push(input);
		}
		else if (pq_less.size() > pq_greater.size()) // 왼쪽이 더 많을 경우
		{
			int top_ls = pq_less.top();

			// input이 더 작을 경우
			if (top_ls > input)
			{
				pq_less.pop();
				pq_greater.push(top_ls);
				pq_less.push(input);
			}
			else
			{
				pq_greater.push(input);
			}
		}
		else // 사이즈가 같을 경우
		{
			int top_gt = pq_greater.top();
			if (top_gt > input)
			{
				pq_less.push(input);
			}
			else
			{
				pq_greater.pop();
				pq_less.push(top_gt);
				pq_greater.push(input);
			}
		}

		cout << pq_less.top() << '\n';

	}

}