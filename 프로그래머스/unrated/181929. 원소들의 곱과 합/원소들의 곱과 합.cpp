#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int mulresult = 1;
    int addresult = 0;
    for (int n : num_list)
    {
        mulresult *= n;
        addresult += n;
    }
    addresult *= addresult;
    
    return (mulresult < addresult ? 1 : 0);
}