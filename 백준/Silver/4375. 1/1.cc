#include<iostream>
using namespace std;
/*
(a * b) % n  = (a % n) * (b % n)
*/
int DigitData(int n)
{
	int data = 1;

	int N = 1;
	while (1)
	{
		if (data % n == 0)
			return N;
		else
		{
			data = data * 10 + 1;
			data %= n;
			N++;
		}
	}
	return 0;

}
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		cout << DigitData(n) << endl;
	}
	
	return 0;
}