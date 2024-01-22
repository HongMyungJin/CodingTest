#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	unsigned int dice1, dice2, dice3, reward = 0;

	cin >> dice1 >> dice2 >> dice3;


	if ((dice1 == dice2) && (dice1 == dice3))
		reward = 10000 + dice1 * 1000;
	else if ((dice1 == dice2) || (dice1 == dice3))
		reward = 1000 + dice1 * 100;
	else if (dice2 == dice3)
		reward = 1000 + dice2 * 100;
	else
		reward = max(max(dice1, dice2), dice3) * 100;

	cout << reward << endl;
}