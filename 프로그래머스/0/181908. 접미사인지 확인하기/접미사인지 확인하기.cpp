#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string my_string, string is_suffix) {
    vector<string> suffix;
    for (int i = 0; i < my_string.length(); i++)
        suffix.push_back(my_string.substr(i));
    if (find(suffix.begin(), suffix.end(), is_suffix) != suffix.end())
        return 1;
    else
        return 0;
}