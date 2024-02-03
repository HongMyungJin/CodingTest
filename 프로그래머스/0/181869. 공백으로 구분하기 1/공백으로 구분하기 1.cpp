#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> solution(string my_string) {
    stringstream ss(my_string);
    vector<string> answer;
    string word;
    
    while(getline(ss, word, ' '))
        answer.emplace_back(word);
    return answer;
}