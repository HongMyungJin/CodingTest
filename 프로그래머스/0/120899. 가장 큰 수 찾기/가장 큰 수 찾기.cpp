#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    answer.resize(2);
    int max = -1;
    for(int i = 0; i < array.size(); i++)
    {
        if (max < array[i])
        {
            max = array[i];
            answer[0] = max;
            answer[1] = i;
        }
    }
    return answer;
}