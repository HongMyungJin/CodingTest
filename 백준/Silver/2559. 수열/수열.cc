#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
int main()
{
    int N;
    int Day;
    std::vector<int> PrefixSum = { 0, };

    std::cin >> N;
    std::cin >> Day;

    PrefixSum.resize(N + 1);

    for (int i = 1; i < N + 1; i++)
    {
        std::cin >> PrefixSum[i];
        PrefixSum[i] += PrefixSum[i - 1];
    }

    int CurValue = 0;
    int Max = INT_MIN;
    for (int t = 1; t < N + 2 - Day; t++)
    { 
        CurValue = PrefixSum[t + Day - 1] - PrefixSum[t - 1];
        Max = std::max(Max, CurValue);
    }

    std::cout << Max << std::endl;
    return 0;
}