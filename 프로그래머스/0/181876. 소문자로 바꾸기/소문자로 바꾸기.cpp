#include <string>

using namespace std;

string solution(string myString) {
    for(char& st : myString)
        st = tolower(st);
    return myString;
}