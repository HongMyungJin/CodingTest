#include <string>
#include <algorithm>

using namespace std;

string solution(string my_string, string alp) {
    int pos = my_string.find(alp);
    while(pos != my_string.npos)
    {
        string st = " ";
        st[0] = toupper(alp[0]);
        my_string.replace(pos, alp.length(), st);
        pos = my_string.find(alp);
    }
    return my_string;
}