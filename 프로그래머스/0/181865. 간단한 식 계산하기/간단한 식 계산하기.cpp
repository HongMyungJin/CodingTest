#include <string>
#include <vector>
#include <sstream>
using namespace std;

int solution(string binomial) {
    vector<string> words;
    
    string word;
    stringstream ss(binomial);
    while(ss >> word)
        words.emplace_back(word);
    
    int num1 = stoi(words[0]);
    int num2 = stoi(words[2]);
    
    return words[1] == "+" ? num1 + num2 : words[1] == "-" ? num1 - num2 : num1 * num2;
}