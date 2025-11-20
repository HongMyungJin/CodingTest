#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int ROW = 4;
const int COL = 4;
vector<vector<int>> inputs(ROW, vector<int>(COL, 0));

map<char, int> inputDir = {{'R', 1}, {'L', 3}, {'U', 2}, {'D', 0}};

char dir;

void DropData()
{
    // 열 단위로
    for (int drop = 0; drop < 4; drop++)
    {
        for (int col = 0; col < 4; col++)
        {
            // 행 단위로 아래부터
            for (int row = ROW - 1; row >= 1; row--)
            {
                // 0일 경우 위에 있는거 내리기
                if (inputs[row][col] == 0 && inputs[row - 1][col] != 0 )
                {
                    inputs[row][col] = inputs[row - 1][col];
                    inputs[row - 1][col] = 0;
                }
            }
        }
    }

}

// 90도 회전(상, 하, 좌, 우에 따른)
void RotateDataRev()
{
    vector<vector<int>> rotateData(4, vector<int>(4, 0));
        // 열 단위로
        for (int row = 0; row < 4; row++)
        {
            // 아래부터
            for (int col = 0; col < 4; col++)
            {
                rotateData[row][col] = inputs[col][4 - 1 -row];
            }
        }
    inputs = rotateData;
}

void RotateData()
{
    vector<vector<int>> rotateData(4, vector<int>(4, 0));
        // 열 단위로
        for (int row = 0; row < 4; row++)
        {
            // 아래부터
            for (int col = 0; col < 4; col++)
            {
                rotateData[row][col] = inputs[4 - 1 - col][row];
            }
        }
    inputs = rotateData;
}

void Combine()
{
    // 열 단위로
    for (int i = 0; i < COL; i++)
    {
        // 행 단위로 아래부터
        for (int j = COL - 1; j >= 1; j--)
        {
            // 만약 위에 있는거랑 같은 값일 경우, j - 1이 0 이상이고
            if (inputs[j][i] == inputs[j - 1][i] && inputs[j][i] != 0)
            {
                inputs[j][i] *= 2;
                inputs[j - 1][i] = 0;

                // 합쳤으니 한칸 더 위로 올리기
                j--;
            }
        }
    }
}

void Print()
{
    // 열 단위로
    for (int i = 0; i < ROW; i++)
    {
        // 행 단위로 아래부터
        for (int j = 0; j < COL; j++)
        {
            cout << inputs[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    // Please write your code here.
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cin >> inputs[i][j];
        }
    }

    cin >> dir;

    // 방향에 따른 회전
    int n = inputDir[dir] % 4;

    for (int i = 0; i < n; i++)
        RotateData();
    // 중력 적용
    DropData();
    // 합치기
    Combine();
    // 빈곳 다시 중력 작용
    DropData();

    // 다시 회전 원복

    for (int i = 0; i < n; i++)
        RotateDataRev();

    Print();
    return 0;
}