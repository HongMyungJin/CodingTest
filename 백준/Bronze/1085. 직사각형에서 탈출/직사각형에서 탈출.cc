#include<iostream>
using namespace std;

int Absolute(int A, int B);
int Small(int A, int B);
int main()
{
	int x, y, w, h;

	cin >> x >> y;
	cin >> w >> h;

	cout << Small(Small(Absolute(x, w), Absolute(y, h)), Small(x, y)) << endl;

	
}

int Absolute(int A, int B)
{
	if (A - B >= 0)
		return (A - B);
	else
		return (B - A);
}

int Small(int A, int B)
{
	if (A > B)
		return B;
	else
		return A;
}