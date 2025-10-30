using System;
using System.Collections.Generic;

public class Codetree
{
    private static int N;
    private static int M;

    private static int[] dirX = { 0, 0, -1, 1 };
    private static int[] dirY = { -1, 1, 0, 0 };

    private static List<List<int>> BFS;
    private static List<List<bool>> Visited;
    private static Queue<(int, int)> Q;

    private static bool IsInRange(int x, int y)
    {
        return x >= 0 && y >= 0 && x < N && y < N;
    }
    private static bool Solve()
    {
        Q.Enqueue((0, 0));
        Visited[0][0] = true;

        while (Q.Count > 0)
        {
            var (x, y) = Q.Dequeue();

            if (x == N - 1 && y == N - 1)
            {
                return true;
            }

            for (int i = 0; i < 4; i++)
            {
                int newX = x + dirX[i];
                int newY = y + dirY[i];

                if (IsInRange(newX, newY) && !Visited[newY][newX] && BFS[newY][newX] == 1)
                {
                    Visited[newY][newX] = true;
                    Q.Enqueue((newX, newY));
                }
            }
        }
        // 방문했거나 BFS가 0이면 다음으로
        return false;

    }

    public static void Main()
    {
        // Please write your code here.
        string[] inputs = Console.ReadLine().Split(' ');

        N = int.Parse(inputs[0]);
        M = int.Parse(inputs[1]);

        BFS = new List<List<int>>();
        Visited = new List<List<bool>>();

        Q = new Queue<(int, int)>();
        

        for (int i = 0; i < N; i++)
        {
            string[] lines = Console.ReadLine().Split(' ');

            BFS.Add(new List<int>());
            Visited.Add(new List<bool>());

            for (int t = 0; t < N; t++)
            {
                BFS[i].Add(int.Parse(lines[t]));
                Visited[i].Add(false);
            }
        }

        if (Solve())
        {
            Console.Write(1);
        }
        else
        {
            Console.Write(0);
        }

    }
}
