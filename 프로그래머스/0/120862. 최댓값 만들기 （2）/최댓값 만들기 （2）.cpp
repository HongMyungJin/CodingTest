#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    
    int data1 = numbers[0] * numbers[1];
    int data2 = numbers[numbers.size() - 1] * numbers[numbers.size() - 2];
    
    return data1 > data2 ? data1 : data2;
}