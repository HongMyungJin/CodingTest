#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    answer.resize(2);
    for(int i : num_list)
        answer[i % 2]++;

    return answer;
}