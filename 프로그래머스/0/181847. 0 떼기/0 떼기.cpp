#include <string>
#include <vector>

using namespace std;

string solution(string n_str) 
{
    int posN = 0;
    for(char ch : n_str)
    {
        if(ch != '0')
            break;
        posN++;
    }
    n_str.erase(n_str.begin(), n_str.begin() + posN);
    return n_str;
}