#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    answer.reserve(queries.size());
    
    for (vector<int>& query : queries)
    {
        int min = -1;
        int idx = -1;
        for (int i = query[0]; i <= query[1]; i++)
        {
            if ((query[2] < arr[i]) && ((min == -1) || (min > arr[i])))
                min = arr[i];
        }
        answer.push_back(min);
    }
    return answer;

}