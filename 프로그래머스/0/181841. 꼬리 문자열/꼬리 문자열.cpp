#include <string>
#include <vector>
#include <regex>

using namespace std;

string solution(vector<string> str_list, string ex) {
    string answer = "";
    for(string& st : str_list)
    {
        if(st.find(ex) == string::npos)
            answer += st;
    }
    return answer;
}