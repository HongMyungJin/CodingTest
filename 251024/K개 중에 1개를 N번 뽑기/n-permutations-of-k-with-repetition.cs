using System;
using System.Collections.Generic;

public class Codetree
{  
    private static List<int> listData;
    private static int K, N;

    private static void Choice(int cur_num)
    {
        if (cur_num == N + 1) // 종료하고 출력
        {
            foreach (int value in listData)
            {
                Console.Write(value);
                Console.Write(" ");
            }
            Console.WriteLine();
            return;
        }


        for (int s = 1; s <= K; s++)
        {
            listData.Add(s);
            Choice(cur_num + 1);
            listData.RemoveAt(listData.Count - 1);
        }
    }

    public static void Main()
    {
        listData = new List<int>();
        // Please write your code here.
        string[] input = Console.ReadLine().Split(' ');
        
        K = int.Parse(input[0]);
        N = int.Parse(input[1]);

        Choice(1);
    }
}