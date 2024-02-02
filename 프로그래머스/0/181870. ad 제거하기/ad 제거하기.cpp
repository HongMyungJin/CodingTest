#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strArr) {
    strArr.erase(remove_if(strArr.begin(), strArr.end(), [](string st){return st.find("ad") != string::npos;}), strArr.end());
    return strArr;
}