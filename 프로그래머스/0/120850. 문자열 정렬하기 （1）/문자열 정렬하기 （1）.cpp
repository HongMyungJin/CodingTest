#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    for(char i : my_string)
    {
        if(i >= '0' && i <= '9')
            answer.push_back(i - '0');
    }
    sort(answer.begin(), answer.end());
    return answer;
}