#include<iostream>
using namespace std;
int Not_Same(int A, int B, int C);
int main()
{
	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	cout << Not_Same(x1, x2, x3) << " " << Not_Same(y1, y2, y3) << endl;
}

int Not_Same(int A, int B, int C)
{
	if (A == B)
		return C;
	else if(A == C)
		return B;
	else
		return A;
}