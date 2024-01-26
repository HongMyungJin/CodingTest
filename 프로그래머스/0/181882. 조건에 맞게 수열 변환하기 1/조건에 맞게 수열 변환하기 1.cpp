#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    for (int& value : arr)
    {
        if(50 <= value && (value % 2 == 0))
            value /= 2;
        else if(50 > value && (value % 2 == 1))
            value *= 2;
    }
    return arr;
}