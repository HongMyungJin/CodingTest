#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int idx = myString.find(pat, idx);
    int num = 0;
    while (idx != -1)
    {
        idx++;
        num++;
        idx = myString.find(pat, idx);
    }

    return num;
}