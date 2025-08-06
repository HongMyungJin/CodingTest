#include <iostream>
#include <map>
using namespace std;


string GetParent(map<string, string>& parents, string parent)
{
	if (parents[parent] == parent)
		return parent;

	return parents[parent] = GetParent(parents, parents[parent]);
}

bool IsFriend(string A, string B, map<string, string>& parents)
{
	string parentA = GetParent(parents, A);
	string parentB = GetParent(parents, B);

	return parentA == parentB;
}


void Merge(string A, string B, map<string, string>& parents, map<string, int>& size)
{
	string parentA = GetParent(parents, A);
	string parentB = GetParent(parents, B);

	if (parentA == parentB)
		return;

	if (parentA > parentB)
	{
		parents[parentA] = parentB;
		size[parentB] += size[parentA];

	}
	else
	{
		parents[parentB] = parentA;
		size[parentA] += size[parentB];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, F;

	cin >> T;

	map<string, int> size;
	for (int t = 0; t < T; t++)
	{
		map<string, string> data;
		cin >> F;
		for (int f = 0; f < F; f++)
		{
			string value[2];
			cin >> value[0] >> value[1];

			for (int i = 0; i < 2; i++)
			{
				if (data.count(value[i]) == 0)
				{
					data[value[i]] = value[i];
					size[value[i]] = 1;
				}
			}

			Merge(value[0], value[1], data, size);

			string parent = GetParent(data, value[0]);

			cout << size[parent] << '\n';
		}
	}

	return 0;
}