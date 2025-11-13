#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> blocks[2]= 
{
{
    {1, 0},
    {1, 1}
},
{
    {1, 1, 1}
}
};

int N, M;

bool InRange(int row, int col)
{
    return row >= 0 && col >= 0 && row < N && col < M;
}

vector<vector<int>> rotate(const vector<vector<int>>& data)
{
    int h = data.size();
    int w = data[0].size();
    
    vector<vector<int>> r(w, vector<int>(h, 0));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            r[j][h - 1 - i] = data[i][j];
        }
    }

    return r;
}

int main() {
    // Please write your code here.

    int max = 0;
    cin >> N >> M;
    // N: 행, M: 열
    vector<vector<int>> values(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> values[i][j];
        }
    }

    for (int block = 0; block < 2; block++)
    {
        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < M; c++)
            {
                // 모든 블록을 체크
                auto cur = blocks[block];
                
                for (int rot = 0; rot < 4; rot++)
                {
                    int sum = 0;
                    bool ok = true;

                    for (int t = 0; t < cur.size(); t++)
                    {
                        for(int p = 0; p < cur[t].size(); p++)
                        {
                            // 회전 적용

                            // 블록이 없는 경우
                            if (cur[t][p] == 0)
                            {
                                continue;
                            }

                            int newRow = r + t;
                            int newCol = c + p;

                            // 내부에 없음.
                            if (!InRange(newRow, newCol))
                            {
                                ok = false;
                                break;
                            }
                            sum += values[newRow][newCol];
                        }

                        if (!ok)
                        {
                            break;
                        }
                    }

                    if (ok)
                    {
                        max = max < sum ? sum : max;
                    }
                    cur = rotate(cur);
                }
                
            }
        }
    }

    cout << max;
    
    return 0;
}