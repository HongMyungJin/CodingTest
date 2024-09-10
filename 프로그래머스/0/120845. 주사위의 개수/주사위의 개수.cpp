#include <string>
#include <vector>

using namespace std;

int solution(vector<int> box, int n) {
    int N = 1;
    for(int i = 0; i < box.size(); i++)
        N *= box[i] / n;
    return N;
}