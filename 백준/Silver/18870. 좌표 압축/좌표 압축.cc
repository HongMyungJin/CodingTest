#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(0);
	std::cout.tie(0);

	int N;
	std::cin >> N;
	std::vector<int> value(N);
	std::vector<int> saveValue(N);

	for(int i = 0; i < N; i++){ 
		std::cin >> value[i];
	}

	saveValue = value;
	std::sort(saveValue.begin(), saveValue.end());
	saveValue.erase(std::unique(saveValue.begin(), saveValue.end()), saveValue.end());

	for (int i = 0; i < value.size(); i++){
		std::cout << std::lower_bound(saveValue.begin(), saveValue.end(), value[i]) - saveValue.begin() << " ";
	}
	return 0;
}