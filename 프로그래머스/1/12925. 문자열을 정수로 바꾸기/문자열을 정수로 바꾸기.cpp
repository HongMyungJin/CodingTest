#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    if(s[0] == '-') // 음수
    {
        s.erase(s.begin());
        answer = -stoi(s);
    }
    else // 양수
        answer = stoi(s);
    return answer;
}