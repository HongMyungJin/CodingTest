#include <iostream>
#include <algorithm>
#include <array>
int Sum(std::array<int, 9> iheight, int i, int j)
{
	int itotal = 0;
	for (int t = 0; t < 9; t++)
	{
		if (i != t && j != t)
			itotal += iheight[t];
	}
	return itotal;
}

void Find(std::array<int, 9>& iheight)
{
	int t = 0;
	int total = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 1 + t; j < 9; j++)
		{
			if (100 == Sum(iheight, i, j))
			{
				iheight[i] = 101;
				iheight[j] = 101;
			}
		}
		t++;
	}
}
int main()
{
	// 10명 입력
	std::array<int, 9> iHeight = {};
	for (int i = 0; i < 9; i++)
	{
		std::cin >> iHeight[i];
	}

	// 조합으로 푼다. (순서 중요x)
	// 두 명을 빼고 더해서 100이 되는 것
	// 01, 02, 03, 04, 05, 06, 07, 08
	// 12, 13, 14, 15, 16, 17, 18

	Find(iHeight);
	std::sort(iHeight.begin(), iHeight.end());
	for (int i = 0; i < 7; i++)
		std::cout << iHeight[i] << std::endl;
	return 0;
}