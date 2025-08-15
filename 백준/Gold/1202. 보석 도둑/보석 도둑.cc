#include <iostream>
#include <queue>
using namespace std;

struct CMP
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second < b.second;
	}
};
int main()
{
	int N, K, M, V, C;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> jewerlys;
	priority_queue<int, vector<int>, greater<>> bags;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> M >> V;
		jewerlys.push(make_pair(M, V));
	}

	for (int i = 0; i < K; i++)
	{
		cin >> C;
		bags.push(C);
	}

	long long price = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, CMP> jewerlyData;
	while (!bags.empty())
	{
		while (!jewerlys.empty() && jewerlys.top().first <= bags.top())
		{
			jewerlyData.push(jewerlys.top());
			jewerlys.pop();
		}
		if (!jewerlyData.empty())
		{
			price += jewerlyData.top().second;
			jewerlyData.pop();
		}

		bags.pop();
	}

	cout << price;
}