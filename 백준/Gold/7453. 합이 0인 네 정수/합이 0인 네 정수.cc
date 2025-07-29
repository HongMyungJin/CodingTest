#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	vector<int> values[4];
	for (int i = 0; i < 4; i++)
	{
		values[i].resize(n);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> values[j][i];
		}
	}

	vector<int> addAB, addCD;

	addAB.resize(n * n);
	addCD.resize(n * n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			addAB[i * n + j] = values[0][i] + values[1][j];
			addCD[i * n + j] = values[2][i] + values[3][j];
		}
	}

	sort(addAB.begin(), addAB.end());
	sort(addCD.begin(), addCD.end(), greater<>());
	int left = 0;
	int right = 0;

	long long valueN = 0;
	while (left < addAB.size() && right < addCD.size())
	{
		int sum = addAB[left] + addCD[right];

		if (sum > 0)
		{
			right++;
		}
		else if (sum < 0)
		{
			left++;
		}
		else
		{
			int valueAB = addAB[left];
			int valueCD = addCD[right];

			long long cntAB = 0;
			long long cntCD = 0;
			while (left < addAB.size() && addAB[left] == valueAB)
			{
				left++;
				cntAB++;
			}
			while (right < addCD.size() && addCD[right] == valueCD)
			{
				right++;
				cntCD++;
			}

			valueN += cntAB * cntCD;
		}
	}

	cout << valueN;
	return 0;
}