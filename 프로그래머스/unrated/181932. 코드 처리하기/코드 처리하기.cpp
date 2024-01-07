#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    bool mode = false;
    string answer = "";
    for (int i = 0; i < code.length(); i++)
    {
        if (code[i] == '1')
            mode = !mode;
        else if (((!mode) && (i % 2 == 0)) || (mode && (i % 2 == 1)))
            answer += code[i];
    }
    if(answer == "")
        answer = "EMPTY";
    return answer;
}