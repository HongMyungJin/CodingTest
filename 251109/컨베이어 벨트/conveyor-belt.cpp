#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n, T;

    cin >> n >> T;
    vector<int> values(n * 2, 0);

    for (int j = 0; j < values.size(); j++)
    {
        cin >> values[j];
    }

    for (int t = 0; t < T; t++)
    {
        int temp = values[n * 2 - 1];
        for (int i = n * 2 -1; i >= 1; i--)
        {
            values[i] = values[i - 1];
        }

        values[0] = temp;
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << values[i * n + j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}