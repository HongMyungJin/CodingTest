#include <vector>
#include <math.h>

using namespace std;

int solution(int a, int b, int c, int d) {
    int reward = 0;
    if ((a == b) && (b == c) && (c == d))
        reward = 1111 * a;
    else if ((a == b) && (b == c)) // abc
        reward = pow((10 * a + d), 2);
    else if ((a == c) && (c == d)) // acd
        reward = pow((10 * a + b), 2);
    else if ((a == b) && (b == d)) // abd
        reward = pow((10 * a + c), 2);
    else if ((b == c) && (c == d)) // bcd
        reward = pow((10 * b + a), 2);
    else if ((a == b) && (c == d)) // ab == cd
        reward = (a + c) * abs(a - c);
    else if ((a == c) && (b == d)) // ac == bd
        reward = (a + b) * abs(a - b);
    else if ((a == d) && (b == c)) // ad == bc
        reward = (a + b) * abs(a - b);
    else if (a == b)
        reward = c * d;
    else if (a == c)
        reward = b * d;
    else if (a == d)
        reward = b * c;
    else if (b == c)
        reward = a * d;
    else if (b == d)
        reward = a * c;
    else if (c == d)
        reward = a * b;
    else
        reward = min(min(min(a, b), c), d);

    return reward;
}