#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	int N, M, R;
	int u, v;
	cin >> N >> M >> R;

	vector<vector<int>> adjs(N + 1);
	vector<int> visited(N + 1, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		adjs[u].push_back(v);
		adjs[v].push_back(u);
	}

	for (int i = 0; i < N + 1; i++)
	{
		sort(adjs[i].begin(), adjs[i].end());
	}

	stack<int> s;
	s.push(R);

	int visit = 0;
	while (!s.empty())
	{
		int cur = s.top();
		s.pop();

		if (visited[cur] == 0)
		{
			visited[cur] = ++visit;
		}

		for (int i = 0; i < adjs[cur].size(); i++)
		{
			if (visited[adjs[cur][i]] == 0)
			{
				s.push(adjs[cur][i]);
			}
		}
	}

	for (int i = 1; i < visited.size(); i++)
	{
		cout << visited[i] << '\n';
	}
}