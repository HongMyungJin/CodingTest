using System;
using System.Collections.Generic;

public class Codetree
{
    private static int N;
    private static int M;

    private static List<int> combines;

    // 총 N의 수 중 M개를 뽑는 경우의 수
    // 오름차순일 경우에만 Print

    private static bool IsIncrease()
    {
        for (int i = 1; i < combines.Count; i++)
        {
            if (combines[i - 1] >= combines[i])
            {
                return false;
            }
        }

        return true;
    }

    private static void Solve(int count)
    {

        if (count == M && IsIncrease())
        {
            // 출력
            foreach (int value in combines)
            {
                Console.Write($"{value} ");
            }

            Console.Write('\n');

            return;
        }

        for (int i = count + 1; i <= N; i++)
        {
            combines.Add(i);

            Solve(count + 1);

            combines.RemoveAt(combines.Count - 1);
        }
    }
    public static void Main()
    {
        // Please write your code here.
        string[] values = Console.ReadLine().Split(' ');
        combines = new List<int>();

        N = int.Parse(values[0]);
        M = int.Parse(values[1]);

        Solve(0);
    }
}
