#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int i = 1;
	int MultiplierSix = 6;
	int first = 1;
	int last = 1;
	if (n == 1)
	{
		cout << 1 << endl;
	}
	else
	{
		for (;i <= n;)
		{
			i++;
			first = last + 1;
			last += MultiplierSix;
			MultiplierSix += 6;
			if (first <= n && last >= n)
			{
				cout << i << endl;
				break;
			}
			
		}
	}
}