#include <cmath>

using namespace std;

int solution(int a, int b) {
    return ((a % 2) == 1) && ((b % 2) == 1) ? pow(a, 2) + pow(b, 2) : ((a % 2) == 1) || (b % 2) == 1 ? 2 * (a + b) : abs(a - b);
}