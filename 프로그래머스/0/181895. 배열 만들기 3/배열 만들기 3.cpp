#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;
    for(vector<int>& intervalValues : intervals)
    {
        for(int i = intervalValues[0]; i <= intervalValues[1]; i++)
            answer.emplace_back(arr[i]);
    }
    return answer;
}