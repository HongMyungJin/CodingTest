#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
	vector<int> answer;
	int Start, End, Interval = 0;
	switch (n)
	{
	case 1:
		Start = 0, End = slicer[1], Interval = 1;
		break;
	case 2:
		Start = slicer[0], End = num_list.size() - 1, Interval = 1;
		break;
	case 3:
		Start = slicer[0], End = slicer[1], Interval = 1;
		break;
	case 4:
		Start = slicer[0], End = slicer[1], Interval = slicer[2];
		break;
	}
	for (int i = Start; i <= End; i += Interval)
		answer.emplace_back(num_list[i]);

	return answer;
}