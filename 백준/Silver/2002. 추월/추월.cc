#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, int> mapValues;
vector<string> inputData;
int GetMinIndex(int startIndex)
{
	int min = inputData.size();

	for (int i = startIndex; i < inputData.size(); i++)
	{
		int value = mapValues[inputData[i]];
		if (min > value)
			min = value;
	}

	return min;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;

	cin >> N;

	string data;
	for (int i = 0; i < N; i++)
	{
		cin >> data;
		mapValues[data] = i;
	}

	inputData.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> inputData[i];
	}

	int inputIndex = 0;

	int n = 0;
	while (inputIndex < inputData.size())
	{
		string queueValue = inputData[inputIndex++];

		int idx = mapValues[queueValue];
		int min = GetMinIndex(inputIndex);

		if (idx > min)
		{
			n++;
		}
	}

	cout << n;
	return 0;
}