#include <iostream>
using namespace std;

/*
b == 8
a(8) = a(4) * a(4) => b == 4
a(4) = a(2) * a(2) => b == 2
a(2) = a(1) * a(1) => b == 1
*/

// a를 b번 곱하고 c 나눈 수의 나머지
long long DivideMul(int a, int b, int c)
{
	if (b == 1) return a % c; // 1일 때 연산 종료
	long long value = DivideMul(a, b / 2, c); // a를 b / 2만큼 곱한 값의 c로 나눈 나머지
	value = value * value % c; // 모듈러 연산  (a * b) % c = a % c * b % c
	if (b % 2 == 1) value = value * a % c; // 만약 b가 홀수면 나누기 2했을 경우 1이 남기 때문에 또 곱해준다.

	return value;
}
int main()
{
	int A, B, C;
	cin >> A;
	cin >> B;
	cin >> C;

	cout << DivideMul(A, B, C) << endl;

	return 0;
}