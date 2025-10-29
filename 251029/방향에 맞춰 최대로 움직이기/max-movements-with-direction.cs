using System;
using System.Collections.Generic;
public class Codetree
{  

    private static int N;

    private static int Max;

    private static List<List<int>> Grid;
    private static List<List<int>> Dirs;
    private static List<List<bool>> Visited;

    private static int[] dirX = {0, 1, 1, 1, 0, -1, -1, -1};
    private static int[] dirY = {-1, -1, 0, 1, 1, 1, 0, -1};

    private static bool InRange(int row, int col)
    {
        return row >= 0 && col >= 0 && row < N && col < N;
    }

    private static bool IsBig(int cur, int next)
    {
        return cur < next;
    }

    private static void Solve(int row, int col, int score)
    {
        Max = Math.Max(score, Max);

        // 이동 가능한지 체크
        int dir = Dirs[row][col];
        // 해당 칸의 방향 모두 시도
        for (int dist = 1; dist < N; dist++)
        {
            int newRow = row + dirY[dir] * dist;
            int newCol = col + dirX[dir] * dist;

            // 다음도 진행할 필요x 해당x
            if (!(InRange(newRow, newCol)))
            {
                break;
            }
            // 이미 방문
            if (Visited[newRow][newCol])
            {
                continue;
            }
            
            // 현재 값 크기와 이후 값 크기 비교
            if (!IsBig(Grid[row][col], Grid[newRow][newCol]))
            {
                continue;
            }

            Visited[newRow][newCol] = true;
            Solve(newRow, newCol, score + 1);
            Visited[newRow][newCol] = false;
        }
    }

    public static void Main()
    {
        // Please write your code here.
        string[] inputs = Console.ReadLine().Split(' ');

        N = int.Parse(inputs[0]);
        Max = 0;

        Grid = new List<List<int>>();
        Visited = new List<List<bool>>();
        for (int i = 0; i < N; i++)
        {
            Grid.Add(new List<int>());   
            Visited.Add(new List<bool>());   
            string[] inputNs = Console.ReadLine().Split(' ');
            for (int t = 0; t < inputNs.Length; t++)
            {
                Grid[i].Add(int.Parse(inputNs[t]));
                Visited[i].Add(false);
            }
        }

        Dirs = new List<List<int>>();
        for (int i = 0; i < N; i++)
        {
            Dirs.Add(new List<int>());   
            string[] inputNs = Console.ReadLine().Split(' ');

            for (int t = 0; t < inputNs.Length; t++)
            {
                Dirs[i].Add(int.Parse(inputNs[t]) - 1);
            }
        }

        string[] inputsRowCol = Console.ReadLine().Split(' ');
        int row = int.Parse(inputsRowCol[0]) - 1;
        int col = int.Parse(inputsRowCol[1]) - 1;
        
        Visited[row][col] = true;
        Solve(row, col, 0);

        Console.Write(Max);
    }
}
