using System;

public class Codetree
{  
    public static void Main()
    {
        int[] dirX = {0, 1, 0, -1};
        int[] dirY = {-1, 0, 1, 0};

        char[] dirValue = {'N', 'E', 'S', 'W'};
        // Please write your code here.
        string[] input = Console.ReadLine().Split(' ');
        int data = int.Parse(input[0]);

        int x = 0;
        int y = 0;

        int time = 0;
        for (int i = 0; i < data; i++)
        {
            string[] inputValue = Console.ReadLine().Split(' ');

            char dir = char.Parse(inputValue[0]);
            int move = int.Parse(inputValue[1]);

            for (int t = 0; t < 4; t++)
            {
                if (dir == dirValue[t])
                {
                    for (int m = 0; m < move; m++)
                    {
                        x += dirX[t];
                        y += dirY[t];

                        time++;

                        if (x == 0 && y == 0)
                        {
                            Console.WriteLine(time);
                            return;
                        }
                    }
                    break;
                }
            }
        }
        Console.WriteLine(-1);
    }
}
