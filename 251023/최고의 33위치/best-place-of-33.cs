using System;

public class Codetree
{  
    static int N;
    private static bool IsRange(int x, int y)
    {
        return x + 3 <= N && y + 3 <= N;
    }

    private static int GetCoin(int[,] board, int x, int y)
    {
        int n = 0;

        for (int i = x; i < x + 3; i++)
        {
            for (int j = y; j < y + 3; j++)
            {
               n += board[i,j];
            }
        }

        return n;
    }
    
    // 0 1 2 3 4
    // 0 1 2 3 4
    public static void Main()
    {
        // Please write your code here.

        N = int.Parse(Console.ReadLine());
        
        int[ , ] board = new int[N, N]; 

        for (int i = 0; i < N; i++)
        {
            string[] input = Console.ReadLine().Split(' ');
            for (int j = 0; j < N; j++)
            {
                board[i, j] = int.Parse(input[j]);
            }
        }

        int maxCoin = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (IsRange(i, j))
                {
                    int coins = GetCoin(board, i, j);
                    maxCoin = coins > maxCoin ? coins : maxCoin;
                }

            }
        }

        Console.Write(maxCoin);

    }
}
