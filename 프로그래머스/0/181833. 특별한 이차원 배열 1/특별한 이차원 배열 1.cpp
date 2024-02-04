#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n);
    for (int i = 0; i < n; i++)
    {
        answer[i].resize(n);
        fill(answer[i].begin(), answer[i].end(), 0);
        answer[i][i] = 1;
    }
    return answer;
}