#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int result = 0;
    for(int i = 0; i < included.size(); i++)
    {
        if(included[i])
            result += a + d * i;
    }

    return result;
}