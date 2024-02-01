#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(string myString, string pat) {
    transform(myString.begin(), myString.end(), myString.begin(), [](char ch) {return ch == 'A' ? 'B' : 'A';});
    
    return myString.find(pat) == string::npos ? 0 : 1;
}