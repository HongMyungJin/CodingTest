using System;
using System.Collections.Generic;
using System.ComponentModel;

public class Codetree
{
    private static int N, M;
    private static List<List<int>> data;
    private static List<bool> visited;
    private static int Max;

    private static void DFS(int vertex, int count)
    {
        Max = Math.Max(Max, count);
        for (int i = 0; i < data[vertex].Count; i++)
        {
            int cur_v = data[vertex][i];
            if (!visited[cur_v])
            {
                visited[cur_v] = true;
                DFS(cur_v, count + 1);
                visited[cur_v] = false;
            }
        }


    }
    public static void Main()
    {
        // Please write your code here.
        string[] values = Console.ReadLine().Split(' ');

        N = int.Parse(values[0]);
        M = int.Parse(values[1]);

        Max = 0;

        data = new List<List<int>>();
        visited = new List<bool>();

        for (int i = 0; i < N; i++)
        {
            data.Add(new List<int>());
        }

        for (int i = 0; i < N; i++)
        {
            visited.Add(false);
        }

        for (int l = 0; l < M; l++)
        {
            string[] pair = Console.ReadLine().Split(' ');

            int first = int.Parse(pair[0]) - 1;
            int second = int.Parse(pair[1]) - 1;

            data[first].Add(second);
            data[second].Add(first);
        }

        for (int i = 0; i < N; i++)
        {
            visited[i] = true;
            DFS(i, 0);
            visited[i] = false;
        }
        

        Console.Write(Max);
    }
}
