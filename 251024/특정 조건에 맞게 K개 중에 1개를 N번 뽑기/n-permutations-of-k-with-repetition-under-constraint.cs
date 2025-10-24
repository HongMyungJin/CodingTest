using System;
using System.Collections.Generic;

public class Codetree
{
    // 연속해서 같은 숫자가 3번 이상일 경우 제외

    private static int K;
    private static int N;
    private static List<int> combines;

    private static bool sameCheck(int n)
    {

        int prevalue = combines[0];
        int same = 1;
        for (int i = 1; i < combines.Count; i++)
        {
            if(combines[i] == prevalue)
            {
                same++;
                if (same >= 3)
                {
                    return false;
                }
            }
            else
            {
                same = 1;
            }
            prevalue = combines[i];
        }
        return true;
    }
    private static void Solve(int curNum)
    {
        if (curNum == N)
        {
            foreach (int num in combines)
            {
                Console.Write($"{num} ");
            }
            Console.Write('\n');
            return;
        }

        for (int i = 1; i <= K; i++)
        {
            combines.Add(i);
            if (!sameCheck(3))
            {
                combines.RemoveAt(combines.Count - 1);
                continue;
            }
            Solve(curNum + 1);
            combines.RemoveAt(combines.Count - 1);
        }

    }

    public static void Main()
    {
        // Please write your code here.
        string[] inputs = Console.ReadLine().Split(' ');

        K = int.Parse(inputs[0]);
        N = int.Parse(inputs[1]);

        combines = new List<int>();

        Solve(0);
    }
}
