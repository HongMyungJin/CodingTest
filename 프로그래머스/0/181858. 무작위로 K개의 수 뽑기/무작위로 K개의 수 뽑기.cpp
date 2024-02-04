#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;

    int idx = 0;
    for (int i = 0; i < arr.size() && answer.size() < k; i++)
    {
        if (find(answer.begin(), answer.end(), arr[i]) == answer.end())
            answer.emplace_back(arr[i]);
    }
    for (; k > answer.size();)
        answer.emplace_back(-1);

    return answer;
}