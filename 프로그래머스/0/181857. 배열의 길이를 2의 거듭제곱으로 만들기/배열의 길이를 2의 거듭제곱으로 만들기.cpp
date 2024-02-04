#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    int power = 1;
    for (; power < arr.size(); power *= 2);

    for (int i = 0; arr.size() < power; i++)
        arr.emplace_back(0);

    return arr;
}