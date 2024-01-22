#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
	vector<int> result;
	int value = 0;
	result.reserve(intStrs.size());
	for (string& str : intStrs)
	{
		str = str.substr(s, l);
		value = stoi(str);
		if(value > k)
			result.push_back(value);
	}
	return result;
}