#include <algorithm>
#include <vector>

using namespace std;
int Function(int i)
{
    if((i >= 50) && (i % 2 == 0))
        i /= 2;
    else if((i < 50) && (i % 2 == 1))
        i = i * 2 + 1;
    
    return i;
}
int solution(vector<int> arr) {
    vector<int> arr0 = arr;
    
    for(int i = 0;; i++)
    {
        transform(arr.begin(), arr.end(), arr.begin(), Function);
        if(arr == arr0)
            return i;
        arr0 = arr;
    }
}