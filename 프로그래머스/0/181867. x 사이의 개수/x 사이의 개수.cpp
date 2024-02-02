#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    string st;
    istringstream iss(myString);
    while(getline(iss, st, 'x'))
        answer.emplace_back(st.length());
    if(myString[myString.length() - 1] == 'x')
        answer.emplace_back(0);
    return answer;
}