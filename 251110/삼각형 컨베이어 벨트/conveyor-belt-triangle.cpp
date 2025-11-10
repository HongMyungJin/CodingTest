#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    int T;

    cin >> N >> T;

    int count = N * 3;
    vector<int> values(N * 3);

    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> values[i * N + j];
        }
    }

    for (int t = 0; t < T; t++)
    {
        int last = values[count - 1];
        for (int i = count - 1; i >= 1; --i)
        {
            values[i] = values[i - 1];
        }
        values[0] = last;
    }

    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << values[i * N + j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}