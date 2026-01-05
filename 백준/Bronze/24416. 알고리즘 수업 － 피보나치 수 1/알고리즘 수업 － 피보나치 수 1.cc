#include <iostream>
#include <vector>
using namespace std;

int play1 = 0;
int play2 = 0;
int fibonacci1(int n)
{

	if (n == 1 || n == 2)
	{
		play1++;
		return 1;
	}
	else
	{
		return (fibonacci1(n - 1) + fibonacci1(n - 2));
	}
}

int fibonacci2(int n)
{
	play2 = 1;
	vector<int> f(n);

	f[1] = f[2] = 1;

	for (int i = 3; i < n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		play2++;
	}

	return f[n - 1];
}

int main()
{
	int n;
	cin >> n;
	fibonacci1(n);
	fibonacci2(n);


	cout << play1 << " " << play2;
}