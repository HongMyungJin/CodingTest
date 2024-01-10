#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int Lastnum = num_list[num_list.size() - 1];
    int Last_2num = num_list[num_list.size() - 2];
    if(Lastnum > Last_2num)
        num_list.emplace_back(Lastnum - Last_2num);
    else
        num_list.emplace_back(Lastnum * 2);
    return num_list;
}