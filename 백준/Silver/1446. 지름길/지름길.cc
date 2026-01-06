#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool InRange(int start, int end, int max)
{
	return start >= 0 && end <= max;
}

struct input
{
	int start;
	int end;
	int value;
};

int main()
{
	int N, D;
	cin >> N >> D;

	vector<int> dp(D + 1);
	vector<input> inputs;

	for (int i = 0; i < D + 1; i++)
	{
		dp[i] = i;
	}
	int start, end, value;

	int max = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> start >> end >> value;
		if (InRange(start, end, D) && end - start > value)
		{
			inputs.push_back({ start, end, value });
		} 
	}

	vector<int> dpEnd(inputs.size());

	sort(inputs.begin(), inputs.end(), [](input& a, input& b) { return a.end < b.end; });

	if (inputs.empty())
	{
		cout << dp[D];
		return 0;
	}
	dp[inputs[0].end] = inputs[0].value + inputs[0].start;
	dpEnd[0] = inputs[0].end;
	for (int i = 1; i < inputs.size(); i++)
	{
		int start = inputs[i].start;
		int end = inputs[i].end;
		int value = inputs[i].value;

		for (int j = i - 1; j >= 0; j--)
		{
			if (start >= dpEnd[j])
			{
				dp[start] = dp[dpEnd[j]] + start - dpEnd[j];
				break;
			}
		}
		// 이전꺼랑 비교했을 때 작은 경우
		int cur = dp[start] + value;
		int preValue = dp[dpEnd[i - 1]] + end - dpEnd[i - 1];

		cur = cur > preValue ? preValue : cur;
		if (dp[end] > cur)
		{
			dp[end] = cur;
		}

		dpEnd[i] = end;
	}

	end = dpEnd[dpEnd.size() - 1];
	dp[D] = dp[end] + D - end;

	cout << dp[D];
}