#include <iostream>
#include <vector>
using namespace std;

bool InRange(int x, int y, int N)
{
    return x >= 0 && y >= 0 && x < N && y < N;
}
int main() {
    // Please write your code here.
    int xMove[] = {0, 0, -1, 1};
    int yMove[] = {-1, 1, 0, 0};

    int N, r, c;

    cin >> N >> r >> c;

    vector<vector<int>> values(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> values[i][j];
        }
    }

    r -= 1;
    c -= 1;
    int max = values[r][c];
    int maxX = c;
    int maxY = r;

    cout << max << ' ';

    bool isBig = true;
    while(isBig)
    {
        isBig = false;
        for (int i = 0; i < 4; i++)
        {
            int nextX = maxX + xMove[i];
            int nextY = maxY + yMove[i];

            if (InRange(nextX, nextY, N) && values[nextY][nextX] > max)
            {
                maxX = nextX;
                maxY = nextY;
                max = values[nextY][nextX];
                cout << max << ' ';
                isBig = true;
                break;
            }
        }
    }
    return 0;
}