#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    for(int i = 0; i < num_list.size() / n; i++)
    {
        int idx = n * i;
        vector<int> vec;
        for(int j = 0; j < n; j++)
            vec.emplace_back(num_list[idx + j]);
        answer.emplace_back(vec);
    }
    return answer;
}