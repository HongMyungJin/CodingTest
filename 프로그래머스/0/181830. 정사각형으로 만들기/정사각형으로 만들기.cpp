#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    int row = arr.size();
    int col = arr[0].size();
    
    if(row > col)
    {
        for(int i = 0; i < row - col; i++)
        {
            for(int j = 0; j < arr.size(); j++)
                arr[j].insert(arr[j].begin() + col + i, 0);
        }
    }
    else
    {
        vector<int> value(col);
        fill(value.begin(), value.end(), 0);
        for(int i = 0; i < col - row; i++)
            arr.insert(arr.begin() + row + i, value);
    }
    return arr;
}