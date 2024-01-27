#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
	int Even = 0;
	int Odd = 0;
	for (int i = 0; i < num_list.size(); i += 2)
	{
		Odd += num_list[i]; // 홀수 번째
		Even += num_list[i + 1]; // 짝수 번째
	}

		if (Even > Odd)
			return Even;
		else
			return Odd;
}