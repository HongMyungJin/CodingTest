#include <iostream>
#include <vector>
using namespace std;

int dirX[] = {1, 0, -1, 0};
int dirY[] = {0, 1, 0, -1};
int N;

bool InRange(int row, int col)
{
    return row >= 0 && col >= 0 && row < N && col < N;
}
 
void Bomb(vector<vector<int>>& values, int row, int col)
{
    row -= 1;
    col -= 1;

    int range = values[row][col];
    values[row][col] = 0;
    for (int r = 1; r < range; r++)
    {
        for (int dir = 0; dir < 4; dir++)
        {
            int newRow = row + dirY[dir] * r;
            int newCol = col + dirX[dir] * r;
            if(InRange(newRow, newCol))
            {
                values[newRow][newCol] = 0;
            }
        }
    }
}
int main() {
    // Please write your code here.

    int row, col;
    cin >> N;

    vector<vector<int>> values(N, vector<int>(N, 0));
    vector<vector<int>> newValues(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> values[i][j];
        }
    }

    cin >> row >> col;
    Bomb(values, row, col);
    
    for (int i = 0; i < N; i++)
    {
        int idx = 0;
        for (int j = N - 1; j >= 0; j--) // 맨 아래꺼부터
        {
            if(values[j][i] != 0)
            {
                int newIndex = N - 1 - idx;
                newValues[newIndex][i] = values[j][i];
                idx++;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << newValues[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}