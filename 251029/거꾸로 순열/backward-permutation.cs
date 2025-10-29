using System;
using System.Collections.Generic;
public class Codetree
{  
    private static int N;
    private static List<int> data;
    private static List<bool> visited;

    private static void Solve(int num)
    {
        if (num == N)
        {
            foreach (int value in data)
            {
                Console.Write($"{value} ");
            }
            Console.Write('\n');

            return;
        }

        for (int i = N - 1; i >= 0; i--)
        {
            if (visited[i])
            {
                continue;
            }
            data.Add(i + 1);
            visited[i] = true;

            Solve(num + 1);

            visited[i] = false;
            data.RemoveAt(data.Count - 1);
        }
    }
    public static void Main()
    {
        // Please write your code here.
        string[] inputs = Console.ReadLine().Split(' ');
        N = int.Parse(inputs[0]);

        data = new List<int>();
        visited = new List<bool>();

        for (int i = 0; i < N; i++)
        {
            visited.Add(false);
        }
        Solve(0);
    }
}
