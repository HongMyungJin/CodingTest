using System;
using System.Collections.Generic;
using System.ComponentModel;

public class Codetree
{
    private static int N, M;
    private static List<List<int>> data;
    private static List<bool> visited;
    private static int Count;

    private static void DFS(int vertex)
    {
        for (int i = 0; i < data[vertex].Count; i++)
        {
            int cur_v = data[vertex][i];

            if (!visited[cur_v])
            {
                visited[cur_v] = true;
                Count++;
                DFS(cur_v);
            }
        }
    }
    public static void Main()
    {
        // Please write your code here.
        string[] values = Console.ReadLine().Split(' ');

        N = int.Parse(values[0]);
        M = int.Parse(values[1]);

        data = new List<List<int>>();
        visited = new List<bool>();

        for (int i = 0; i < N + 1; i++)
        {
            data.Add(new List<int>());
        }

        for (int i = 0; i < N + 1; i++)
        {
            visited.Add(false);
        }

        for (int l = 0; l < M; l++)
        {
            string[] pair = Console.ReadLine().Split(' ');

            int first = int.Parse(pair[0]);
            int second = int.Parse(pair[1]);

            data[first].Add(second);
            data[second].Add(first);
        }

        visited[1] = true;
        DFS(1);
        
        Console.Write(Count);
    }
}
