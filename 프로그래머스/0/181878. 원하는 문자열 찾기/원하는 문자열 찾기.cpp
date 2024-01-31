#include <string>
#include <algorithm>

using namespace std;

int solution(string myString, string pat) {
    transform(myString.begin(), myString.end(), myString.begin(), ::toupper);
    transform(pat.begin(), pat.end(), pat.begin(), ::toupper);
    if(myString.find(pat) == string::npos)
        return 0;
    else
        return 1;
}