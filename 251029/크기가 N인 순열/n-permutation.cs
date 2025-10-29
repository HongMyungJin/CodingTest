using System;
using System.Collections.Generic;

public class Codetree
{
    private static int N;
    private static List<int> Data;
    private static List<bool> Visited;

    private static void Solve(int num)
    {
        if (num == N)
        {
            // Print
            foreach (int value in Data)
            {
                Console.Write($"{value + 1} ");
            }
            Console.Write('\n');
            return;
        }

        for (int i = 0; i < N; i++)
        {
            if (Visited[i])
            {
                continue;
            }

            Data.Add(i);
            Visited[i] = true;
            Solve(num + 1);

            Data.RemoveAt(Data.Count - 1);
            Visited[i] = false;
        }
    }

    public static void Main()
    {
        // Please write your code here.
        string[] inputs = Console.ReadLine().Split(' ');
        N = int.Parse(inputs[0]);
        Data = new List<int>();
        Visited = new List<bool>();

        for (int i = 0; i < N; i++)
        {
            Visited.Add(false);
        }

        Solve(0);
    }
}
