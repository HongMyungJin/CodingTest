#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;
	int N = std::count(arr.begin(), arr.end(), 2);
    if(N == 0)
    {
        answer.emplace_back(-1);
        return answer;
    }
    
	for (vector<int>::iterator i = std::find(arr.begin(), arr.end(), 2); N > 0; i++)
	{
		if (*i == 2) N--;
		answer.emplace_back(*i);
	}
	return answer;
}