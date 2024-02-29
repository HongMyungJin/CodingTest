#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int value = 0;
    for(int i : array)
        if(n == i) value++;
    return value;
}