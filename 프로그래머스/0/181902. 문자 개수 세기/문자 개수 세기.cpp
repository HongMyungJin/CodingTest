#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
	vector<int> answer(52, 0);
	for (int i = 0; i < my_string.length(); i++)
	{
		if(std::isupper(my_string[i]))
			answer[my_string[i] - 'A']++;
		else
			answer[26 + my_string[i] - 'a']++;
	}
	return answer;
}