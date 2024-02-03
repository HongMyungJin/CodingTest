#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    int i = 0;
    
    while(i < arr.size())
    {
        if(stk.empty())
            stk.emplace_back(arr[i]);
        else if(stk.back() == arr[i])
            stk.pop_back();
        else
            stk.emplace_back(arr[i]);
        i++;
    }
    if(stk.empty())
        stk.emplace_back(-1);
    
    return stk;
}