#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;

	cin >> N;

	priority_queue<int, vector<int>, less<>> pq;
	int number1, input;

	cin >> number1;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> input;
		pq.push(input);
	}

	int p = 0;
	int MaxValue;

	while (!pq.empty())
	{
		MaxValue = pq.top();
		if (MaxValue < number1)
			break;
		pq.pop();
		pq.push(MaxValue - 1);
		p++;
		number1++;
	}

	cout << p;
	return 0;
}