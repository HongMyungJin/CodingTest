#include <string>
#include <vector>

using namespace std;

int solution(vector<int> date1, vector<int> date2) {
    for(int i = 0; i < 3;)
    {
        if(date1[i] == date2[i])
            i++;
        else
            return date1[i] < date2[i] ? 1 : 0;
    }
    
    return 0;
}