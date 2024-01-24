#include <iostream>

int main()
{
	int N;
	std::string st;

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> st;
		std::cout << st.front() << st.back() << std::endl;
	}

}