#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> SortN(std::vector<std::string>& values)
{
	std::sort(values.begin(), values.end(), [](std::string a, std::string b)
		{    if (a.length() != b.length()) return a.length() < b.length(); return a < b; }
	);

	values.erase(std::unique(values.begin(), values.end()), values.end());
	return values;
}

int main()
{
	int N;
	std::cin >> N;
	std::vector<std::string> value(N);

	for(int i = 0; i < N; i++){ 
		std::cin >> value[i];
	}

	for (std::string st : SortN(value))
		std::cout << st << "\n";
	return 0;
}