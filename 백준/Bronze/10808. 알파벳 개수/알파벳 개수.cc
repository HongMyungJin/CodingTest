#include <iostream>
#include <string>
#include <array>

int main()
{
	// 26개의 알파벳 개수 보관
	std::array<int, 26> chAlpha = {0, };

	// 입력 단어
	std::string word;

	std::cin >> word;

	for (char ch : word)
		chAlpha[ch - 'a']++;

	for (int i : chAlpha)
		std::cout << i << ' ';
}