#include <string>
#include <vector>

using namespace std;

int solution(string number) {
    int iResult = 0;
    for(int i = 0; i < number.size(); i++)
        iResult += (number[i] - '0');
    return iResult % 9;
}