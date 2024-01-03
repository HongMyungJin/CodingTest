#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;

    int answer0 = stoi(to_string(a) + to_string(b));
    int answer1 = stoi(to_string(b) + to_string(a));
    if (answer0 > answer1)
        answer = answer0;
    else
        answer = answer1;

    return answer;
}