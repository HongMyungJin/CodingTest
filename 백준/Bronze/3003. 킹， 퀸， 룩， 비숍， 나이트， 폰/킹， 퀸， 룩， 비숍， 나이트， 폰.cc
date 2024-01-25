#include <iostream>
#include <array>

using namespace std;
int main()
{
	//킹 1개, 퀸 1개, 룩 2개, 비숍 2개, 나이트 2개, 폰 8개
	std::array<int, 6> Chess;
	std::array<int, 6> CheckChess = { 1, 1, 2, 2, 2, 8 };

	for (int i = 0; i < 6; i++)
	{
		cin >> Chess[i];
		cout << CheckChess[i] - Chess[i] << " ";
	}
}