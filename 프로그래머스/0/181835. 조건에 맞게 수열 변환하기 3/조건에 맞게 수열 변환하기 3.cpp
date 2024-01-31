#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int k) {
    if(k % 2 == 1)
        for(int& i : arr)
            i *= k;
    else
        for(int& i : arr)
            i += k;
    
    return arr;
}