#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<int> indices) {
    for(int i = 0; i < indices.size(); i++)
        my_string[indices[i]] = ' ';
    my_string.erase(remove(my_string.begin(), my_string.end(), ' '), my_string.end());

    return my_string;
}