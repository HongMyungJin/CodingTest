#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    string answer = "";
    int istringLength = str1.length() + str2.length();
    answer.resize(istringLength);
    for(int i = 0; i < str1.length(); i++)
        answer[i * 2] = str1[i];
    
    for(int i = 0; i < str2.length(); i++)
        answer[i * 2 + 1] = str2[i];
    
    return answer;
}