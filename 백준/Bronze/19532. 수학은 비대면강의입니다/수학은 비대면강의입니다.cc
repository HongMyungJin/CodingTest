#include <iostream>
using namespace std;

void Equation(int x1, int y1, int val1, int x2, int y2, int val2)
{   
    int _y1 = y1 * x2;
    int _val1 = val1 * x2;

    int _y2 = y2 * x1;
    int _val2 = val2 * x1;

    int y = 0;
    int x = 0;
    if (_y1 - _y2 == 0)
        y = _val1 / y1;
    else
        y = (_val1 - _val2) / (_y1 - _y2);

    if (x1 == 0)
        x = (val2 - y2 * y) / x2;
    else
        x = (val1 - y1 * y) / x1;
    cout << x << " " << y;

} 

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    Equation(a, b, c, d, e, f);
    return 0;
} 
