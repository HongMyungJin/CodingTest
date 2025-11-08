#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n, m;
    cin >> n >> m;

    vector<vector<int>> values(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> values[i][j];
        }
    }

    int nValue = 0;
    // row
    for (int i = 0; i < n; i++)
    {
        int sequence = 1;
        int max = 0;
        // col
        bool isSequence = false;
        for (int j = 1; j < n; j++)
        {
            if (values[i][j - 1] == values[i][j])
            {
                sequence++;

                max = max < sequence ? sequence : max;
            }
            else
            {
                sequence = 1;
            }
            if (sequence >= m)
            {
                isSequence = true;
            }
        }

        if (isSequence)
        {
            nValue++;
        }
    }

    // col
    for (int i = 0; i < n; i++)
    {
        int sequence = 1;
        int max = 0;
        // col
        bool isSequence = false;
        for (int j = 1; j < n; j++)
        {
            if (values[j - 1][i] == values[j][i])
            {
                sequence++;
            }
            else
            {
                sequence = 1;
            }

            if (sequence >= m)
            {
                isSequence = true;
            }
        }

        if (isSequence)
        {
            nValue++;
        }
    }

    cout << nValue;
    return 0;
}