#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int total = 0;
    if(n % 2 == 0)
    {
        for(int i = n; i > 0; i-=2)
            total += i * i;
    }
    else
    {
        for(int i = n; i > 0; i-=2)
            total += i;
    }
    return total;
}