#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;
    
    for(int i = 0; i < myStr.length(); i++)
    {
        if(myStr[i] == 'a' || myStr[i] == 'b' || myStr[i] == 'c')
            myStr[i] = ' ';    
    }
    
    stringstream ss(myStr);
    string word;
    while(ss >> word)
        answer.emplace_back(word);
    
    if(answer.size() == 0)
        answer.emplace_back("EMPTY");
    
    return answer;
}