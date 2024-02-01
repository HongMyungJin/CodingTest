#include <string>
#include <algorithm>

using namespace std;

string solution(string myString) {
    transform(myString.begin(), myString.end(), myString.begin(), [](char ch){return ch == 'a' ? 'A' : (ch != 'A' ? tolower(ch) : ch);});
    return myString;
}