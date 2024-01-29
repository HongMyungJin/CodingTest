#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> num_list) {
    int total = 1;
    if(num_list.size() >= 11)
        total =  std::accumulate(num_list.begin(), num_list.end(), 0);
    else 
    {
        for(int i : num_list)
            total *= i;
    }
    return total;
}