using System;
using System.Collections.Generic;

public class Codetree
{
    private static int N;
    private static int M;
    private static long Max;
    private static List<int> inputs;
    private static List<int> outputs;

    private static bool CheckIncrease()
    {
        long value = outputs[0];
        for (int i = 1; i < M; i++)
        {
            if (outputs[i - 1] >= outputs[i])
            {
                return false;
            }
        }

        return true;
    }
    private static long XORSolve()
    {
        long xorValue = outputs[0];
        for (int i = 1; i < M; i++)
        {
            xorValue ^= outputs[i];
        }

        return xorValue;
    }

    private static void Solve(int cur)
    {
        if (cur == M)
        {
            if (CheckIncrease())
            {
                Max = Math.Max(XORSolve(), Max);
            }
            return;
        }

        // 애초에 넣을 때 큰 것부터..
        for (int i = 0; i < N; i++)
        {
            // 이전에 넣은 값이 현재 넣을려는 값보다 크면 넘기기
            if (outputs.Count >= 2 && outputs[outputs.Count - 1] >= inputs[i])
            {
                continue;
            }

            outputs.Add(inputs[i]);

            Solve(cur + 1);

            outputs.RemoveAt(outputs.Count - 1);
        }
    }
    public static void Main()
    {
        // Please write your code here.
        string[] values = Console.ReadLine().Split(' ');

        inputs = new List<int>();
        outputs = new List<int>();
        N = int.Parse(values[0]);
        M = int.Parse(values[1]);
        Max = 0;
        string[] valueLists = Console.ReadLine().Split(' ');

        for (int i = 0; i < N; i++)
        {
            inputs.Add(int.Parse(valueLists[i]));
        }

        Solve(0);

        Console.WriteLine(Max);
    }
}
