#include <iostream>
#include <vector>
using namespace std;

int N, M, T;
int dirX[] = {0, 0, -1, 1};
int dirY[] = {-1, 1, 0, 0};

bool InRange(int x, int y)
{
    return x >= 0 && y >= 0 && x < N && y < N;
}
                            // 구슬                         // 값
vector<vector<int>> Move(vector<vector<int>>& values, vector<vector<int>>& inputs)
{
    vector<vector<int>> nextValues(N, vector<int>(N, 0));
     // 구슬이 있는 위치
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // 구슬 있음
            if (values[i][j] == 1)
            {

                int bigValue = 0;
                int idxX = -1;
                int idxY = -1;
                for (int dir = 0; dir < 4; dir++)
                {
                    int newX = i + dirX[dir];
                    int newY = j + dirY[dir];

                    if (InRange(newX, newY) && bigValue < inputs[newX][newY])
                    {
                        bigValue = inputs[newX][newY];
                        idxX = newX;
                        idxY = newY;
                    }
                }
                if (idxX >= 0 && idxY >= 0)
                {
                    nextValues[idxX][idxY]++;
                }
            }
        }
    }
    return nextValues;
}

void Print(vector<vector<int>>& values)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << values[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    // Please write your code here.
    cin >> N >> M >> T;
    vector<vector<int>> inputs(N, vector<int>(N, 0));

    vector<vector<int>> values(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> inputs[i][j];
        }
    }

    int row, col;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> row >> col;
            values[row - 1][col - 1] = 1;
        }
    }

    for (int t = 0; t < T; t++)
    {
        values = Move(values, inputs);
    }

    int n = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (values[i][j] == 1)
            {
                n++;
            }
        }
    }
    cout << n;
    return 0;
}