#include <iostream>
using namespace std;

int main()
{
	int TotalValue, TotalN = 0;
	int Value, N;
	cin >> TotalValue;
	cin >> TotalN;
	for (int i = 0; i < TotalN; i++)
	{
		cin >> Value >> N;
		TotalValue -= Value * N;
	}
	if (TotalValue == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}