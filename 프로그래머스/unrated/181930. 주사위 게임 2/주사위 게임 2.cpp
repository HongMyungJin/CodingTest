#include <vector>
#include <math.h>

using namespace std;

int solution(int a, int b, int c) {
    int result = 0;
    if((a == b) && (a == c) && (b == c))
        result = (a + b + c) * (pow(a, 2) + pow(b, 2) + pow(c, 2)) * (pow(a, 3) + pow(b, 3) + pow(c, 3));
    else if((a == b) || (b == c) || (a == c))
        result = (a + b + c) * (pow(a, 2) + pow(b, 2) + pow(c, 2));
    else
        result = a + b + c;

    return result;
}