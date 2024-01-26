#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> num_list, int n) {
    if(count(num_list.begin(), num_list.end(), n) > 0)
        return 1;
    else
        return 0;
}