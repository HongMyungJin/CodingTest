#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int n) {
    int total = 0;
    for(int num : numbers)
    {
        total += num;
        if(total > n)
            return total;
    }
}