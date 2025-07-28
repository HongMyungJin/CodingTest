#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	long long T;
	int n, m;

	vector<int> A;
	vector<int> B;
	vector<long long> sumA;
	vector<long long> sumB;

	cin >> T;

	cin >> n;
	A.resize(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	cin >> m;
	B.resize(m);

	for (int i = 0; i < m; i++)
	{
		cin >> B[i];
	}

	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += A[j];
			sumA.emplace_back(sum);
		}
	}
	for (int i = 0; i < m; i++)
	{
		int sum = 0;
		for (int j = i; j < m; j++)
		{
			sum += B[j];
			sumB.emplace_back(sum);
		}
	}

	sort(sumA.begin(), sumA.end());
	sort(sumB.begin(), sumB.end(), greater<>());


	int left = 0;
	int right = 0;

	long long sumN = 0;

	while (left < sumA.size() && right < sumB.size())
	{
		long long sum = sumA[left] + sumB[right];
		if (sum < T)
		{
			left++;
		}
		else if (sum > T)
		{
			right++;
		}
		else
		{
			long long a = sumA[left];
			long long b = sumB[right];

			long long valueA = 0;
			long long valueB = 0;
			while (left < sumA.size() && a == sumA[left])
			{
				valueA++;
				left++;
			}
			while (right < sumB.size() && b == sumB[right])
			{
				valueB++;
				right++;
			}
			sumN += valueA * valueB;
		}
	}

	cout << sumN;
	return 0;
}