#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int N, M, R;
vector<vector<int>> VisitPossible;
vector<int> Values;

int main()
{
	cin >> N >> M >> R;

	VisitPossible = vector<vector<int>>(N + 1, vector<int>());
	Values = vector<int>(N + 1, 0);
	stack<int> s;

	int u, v;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		VisitPossible[u].push_back(v);
		VisitPossible[v].push_back(u);
	}

	for (int i = 1; i < N + 1; i++)
	{
		sort(VisitPossible[i].begin(), VisitPossible[i].end(), greater<int>());
	}
	
	int idx = 1;
	s.push(R);
 	while (s.size() > 0)
	{
		int cur = s.top();
		s.pop();

		if (Values[cur] == 0)
		{
			Values[cur] = idx++;
		}

		for (int i = 0; i < VisitPossible[cur].size(); i++)
		{
			int nextIdx = VisitPossible[cur][i];
			if (Values[nextIdx] == 0)
			{
				s.push(nextIdx);
			}
		}
	}

	for (int i = 1; i < N + 1; i++)
	{
		cout << Values[i] << '\n';
	}
}
