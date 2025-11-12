#include <iostream>
#include <vector>
using namespace std;

int N;

bool InRange(int x, int y)
{
    return x >= 0 && y >= 0 && x < N && y < N;
}

int main() {
    // Please write your code here.
    int M, K;

    cin >> N >> M >> K;

    vector<vector<int>> values(N, vector<int>(N, 0));

    // M은 크기
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> values[i][j];
        }
    }

    K -= 1;

    // k는 x 시작점
    // m는 가로 크기
    // 모든 x 좌표 돌기
    // 모든 x 좌표를 기준으로 아래에
    int y = 0;
    bool move = true;
    // 한줄 체크
    while(true)
    {
        for (int x = K; x < K + M; x++)
        {
            // 범위에 있고 1이면 멈추기
            if (InRange(x, y) && values[y][x] == 1)
            {
                move = false;
                break;
            }
        }
        if (!move)
        {
            break;
        }
        y++;
    }

    if (y - 1 >= 0)
    {
        for (int x = K; x < K + M; x++)
        {
            values[y - 1][x] = 1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << values[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}