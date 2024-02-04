#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
  
    vector<int> Values;
    for(int i = l; i <= r; i++)
    {
        string st = to_string(i);
        for(int t = 0; t < st.length(); t++)
        {
            if(!(st[t] == '0' || st[t] == '5'))
                break;
            if(t == st.length() - 1)
                Values.emplace_back(i);
        }
    }
    if(Values.empty())
        Values.emplace_back(-1);
    return Values;
}