#include <string>
#include <vector>

using namespace std;
 
enum class Direction
{
    RightDirection,
    DownDirection,
    LeftDirection,
    UpDirection,
    
};

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n);
    for (int i = 0; i < n; i++)
        answer[i].resize(n);

    Direction moveDirection = Direction::RightDirection;

    int moveN = n;
    int row = 0, col = -1;
    int idx = 1;
    while (1)
    {
        if (idx == n * n + 1)
            break;
        for (int i = 0; i < moveN; i++)
        {
            switch (moveDirection)
            {
            case Direction::RightDirection:
                answer[row][++col] = idx++;
                break;
            case Direction::DownDirection:
                answer[++row][col] = idx++;
                break;
            case Direction::LeftDirection:
                answer[row][--col] = idx++;
                break;
            case Direction::UpDirection:
                answer[--row][col] = idx++;
                break;
            default:
                break;
            }
            
        }
        if (moveDirection == Direction::RightDirection || moveDirection == Direction::LeftDirection)
            moveN--;
        if (col >= n)
            col = n - 1;

        moveDirection = Direction(((int)moveDirection + 1) % 4);
    }
    return answer;
}