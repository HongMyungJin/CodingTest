#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> array, int n) {
    int minGap = 100000000;
    int idx = 0;
    sort(array.begin(), array.end());
    for(int i = 0; i < array.size(); i++)
    {
        if(abs(array[i] - n) < minGap)
        {
            minGap = abs(array[i] - n);
            idx = i;
        }
    }
    return array[idx];
}