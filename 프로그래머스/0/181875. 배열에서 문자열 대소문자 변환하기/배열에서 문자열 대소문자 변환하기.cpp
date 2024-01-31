#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strArr) {
    for(int i = 0; i < strArr.size() / 2; i++)
    {
        transform(strArr[i * 2].begin(), strArr[i * 2].end(), strArr[i * 2].begin(), ::tolower);
        transform(strArr[i * 2 + 1].begin(), strArr[i * 2 + 1].end(), strArr[i * 2 + 1].begin(), ::toupper);
    }
    
    if(strArr.size() % 2 != 0)
        transform(strArr[strArr.size() - 1].begin(), strArr[strArr.size() - 1].end(), strArr[strArr.size() - 1].begin(), ::tolower);
    return strArr;
}