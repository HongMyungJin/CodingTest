#include <string>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    for(int t = i; t <= j; t++)
    {
        for(char ch : to_string(t))
        {
            if(ch - '0' == k)
                answer++;
        }
    }
    return answer;
}