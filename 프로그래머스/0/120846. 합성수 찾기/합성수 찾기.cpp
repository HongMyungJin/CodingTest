#include <string>
#include <vector>

using namespace std;

bool bCompositeNumber(int n)
{
    int iComposite = 0;
    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
            iComposite++;
    }
    
    return iComposite >= 3 ? true : false;
}
int solution(int n) {
        int answer = 0;
    for(int i = 2; i <= n; i++)
    {
        if(bCompositeNumber(i))
            answer++;
    }

    return answer;
}