#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, left, right;

    cin >> N;

    vector<int> values(N, 0);
    vector<int> temps(N, -1);
    for (int i = 0; i < N; i++)
    {
        cin >> values[i];
    }

    int idx = 0;
    int count = N;

    cin >> left >> right;
    for (int t = left - 1; t <= right - 1; t++)
    {
        count--;
        values[t] = -1;
    }
    for (int i = 0; i < N; i++)
    {
        if (values[i] != -1)
        {
            temps[idx++] = values[i];
        }
    }

    cin >> left >> right;
    for (int t = left - 1; t <= right - 1; t++)
    {
        count--;
        temps[t] = -1;
    }

    cout << count << '\n';

    for (int i = 0; i < N; i++)
    {
        if (temps[i] != -1)
            cout << temps[i] << '\n';
    }
    // Please write your code here.
    return 0;
}