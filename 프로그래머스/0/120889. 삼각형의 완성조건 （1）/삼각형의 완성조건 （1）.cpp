#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int maxidx = max_element(sides.begin(), sides.end()) - sides.begin();
    int value = 0;
    for(int i = 0; i < sides.size(); i++)
    {
        if(maxidx != i)
            value += sides[i];
    }
    
    return sides[maxidx] < value ? 1 : 2;
}