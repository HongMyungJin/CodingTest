#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int ROW = 4;
const int COL = 4;
vector<vector<int>> inputs(ROW, vector<int>(COL, 0));
map<char, int> inputDir = {{'R', 1}, {'L', 3}, {'U', 0}, {'D', 2}};

char dir;

void DropData()
{
    // 열 단위로
    for (int i = 0; i < COL; i++)
    {
        // 행 단위로 아래부터
        for (int j = COL - 1; j >= 0; j--)
        {
            // 0일 경우 위에 있는거 내리기
            if (inputs[j][i] == 0 && j - 1 >= 0)
            {
                inputs[j][i] = inputs[j - 1][i];
                inputs[j - 1][i] = 0;
            }
        }
    }

}

// 90도 회전(상, 하, 좌, 우에 따른)
void RotateData(int rotN)
{
    vector<vector<int>> rotateData(ROW, vector<int>(COL, 0));
    for (int r = 0; r < rotN; r++)
    {
        // 열 단위로
        for (int i = 0; i < ROW; i++)
        {
            // 아래부터
            for (int j = 0; j < COL; j++)
            {
                rotateData[i][j] = inputs[ROW - 1 - j][i];
            }
        }
        inputs = rotateData;
    }
}

void Combine()
{
    // 열 단위로
    for (int i = 0; i < COL; i++)
    {
        // 행 단위로 아래부터
        for (int j = COL - 1; j >= 0; j--)
        {
            // 만약 위에 있는거랑 같은 값일 경우, j - 1이 0 이상이고
            if (j - 1 >= 0 && inputs[j][i] == inputs[j - 1][i])
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
    RotateData(inputDir[dir] % 4);
    // 중력 적용
    DropData();
    // 합치기
    Combine();
    // 빈곳 다시 중력 작용
    DropData();

    // 다시 회전 원복
    RotateData((4 - inputDir[dir]) % 4);

    Print();
    return 0;
}