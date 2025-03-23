#include<iostream>
using namespace std;
void Prime_Number(int* PrimeN)
{
	int Prime;
	cin >> Prime;

	if (Prime == 2)
	{
		(*PrimeN)++;
		return;
	}
	for (int i = 2; i < Prime; i++)
	{
		if ((Prime % i) == 0)
		{
			break;
		}
		if ((Prime - 1) == i)
		{
			(*PrimeN)++;
		}
	}
}

int main()
{
	int N;
	cin >> N;

	int PrimeN = 0;
	for (int i = 0; i < N; i++)
	{
		Prime_Number(&PrimeN);
	}
	cout << PrimeN << endl;
}