#include<iostream>
using namespace std;
int main()
{
	int A;
	int B;
	int V;


	cin >> A;
	cin >> B;
	cin >> V;


	if (A == V) 
	{
		cout << 1 << endl;
	}
	else
	{
		int n = (V - A) / (A - B);
		V -= A * n - B * n;
		while (1)
		{
			n++;
			V -= A;
			if (V <= 0)
			{
				cout << n << endl;
				break;
			}
			V -= B;
		}
	}
}

