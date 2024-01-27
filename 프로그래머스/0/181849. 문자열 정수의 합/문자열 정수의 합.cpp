#include <string>
#include <vector>

using namespace std;

int solution(string num_str) {
    int total = 0;
    for(char ch : num_str)
        total += ch - '0';

    return total;
}