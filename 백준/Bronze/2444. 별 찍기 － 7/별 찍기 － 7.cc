#include <iostream>

using namespace std;
int main()
{
	int N;
	cin >> N;
	for (int t = 0; t < N; t++)
	{
		for (int i = 0; i < N - t - 1; i++)
			cout << " ";
		for (int i = 0; i < t * 2 + 1; i++)
			cout << "*";
		cout << endl;
	}
	for (int t = N - 1; t > 0; t--) // t는 1씩 감소 시작은 4
	{
		for (int i = 0; i < N - t; i++) 
			cout << " ";
		for (int i = 0; i < t * 2 - 1; i++)
			cout << "*";
		cout << endl;
	}
}