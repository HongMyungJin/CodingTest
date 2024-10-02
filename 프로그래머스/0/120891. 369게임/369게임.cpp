#include <string>

using namespace std;

int solution(int order) {
    int n = 0;
    for (char ch : to_string(order))
    {
        if (ch > '0' && (ch - '0') % 3 == 0)
            n++;
    }
    return n;
}