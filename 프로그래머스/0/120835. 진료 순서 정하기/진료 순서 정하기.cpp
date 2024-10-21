#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    answer.resize(emergency.size());
    for(int i = 0; i < emergency.size(); i++)
    {
        int idx = max_element(emergency.begin(), emergency.end()) - emergency.begin();
        answer[idx] = i + 1;
        emergency[idx] = -1;
    }
    return answer;
}