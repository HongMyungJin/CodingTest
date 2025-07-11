#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;

	queue<int> cards;
	for (int i = 0; i < n; i++)
	{
		cards.emplace(i + 1);
	}

	while (cards.size() > 1)
	{
		cout << cards.front() << " ";
		cards.pop();

		cards.push(cards.front());
		cards.pop();
	}

	cout << cards.front() << " ";
	return 0;
}