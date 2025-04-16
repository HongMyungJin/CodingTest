#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct POINT
{
	POINT() {}
	POINT(int X, int Y) {
		x = X;
		y = Y;
	}

	int x;
	int y;
};

std::vector<POINT> SortN(std::vector<POINT>& values)
{
	std::sort(values.begin(), values.end(), [](POINT a, POINT b) 
		{    if (a.x != b.x) return a.x < b.x; return a.y < b.y; }
	);
	return values;
}

int main()
{
	int N, x, y;
	std::cin >> N;
	std::vector<POINT> value(N);
	for(int i = 0; i < N; i++){ 
		std::cin >> x >> y;
		value[i] = POINT(x, y);
	}
		

	for (POINT point : SortN(value))
		std::cout << point.x << " " << point.y << "\n";

	return 0;
}