#include <string>

using namespace std;

string solution(string myString, string pat) {
    int LastIndex = myString.rfind(pat);
    return myString.substr(0, LastIndex + pat.length());
}