#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int data;
	unordered_map<int, int> values;
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> data;
		values[data] = data;
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> data;
		
		if (values.count(data) != 0)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';

	}
	return 0;
}