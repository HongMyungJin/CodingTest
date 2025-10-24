using System;
using System.Collections.Generic;

public class Codetree
{  
    // 차근 차근..
    // 일단 모든 폭탄을 두는 경우의 수를 실행해야한다.
    // Solve로 해당 인덱스의 폭탄을 두도록 하자.
    // 그러면 순차적으로 4개를 둬야하면 1, 2, 3, 4로 결정되게 구현한다.
    // 근데 특정 x, y에 둬야하는데

    struct PosData
    {
        public int x;
        public int y;

        public PosData(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }

    static int N;
    static int PosN;
    static int MaxCount;

    static int[,] dirX = 
    new int[,]
    {
        {0, 0, 0, 0},
        {-1, 0, 1, 0},
        {-1, 1, 1, -1}
    };

    static int[,] dirY = 
    new int[,]
    {
        {-1, -2, 1, 2},
        {0, -1, 0, 1},
        {-1, -1, 1, 1}
    };

    static List<List<int>> values;

    static List<PosData> posValues;

    private static bool InRange(int x, int y)
    {
        return x >= 0 && y >= 0 && x < N && y < N;
    }

    private static void Addbomb(int type, int xPos, int yPos, List<(int, int)> changed)
    {
        if (InRange(xPos, yPos) && values[xPos][yPos] == 0)
        {
            changed.Add((xPos, yPos));
            values[xPos][yPos] = 1;
        }

        for (int i = 0; i < 4; i++)
        {
            int x = dirX[type, i] + xPos;
            int y = dirY[type, i] + yPos;

            if (InRange(x, y) && values[x][y] == 0)
            {
                values[x][y] = 1;
                changed.Add((x, y));
            }
        }
    }
    
    private static void RemoveBomb(List<(int, int)> changed)
    {
        foreach ((int x, int y) in changed)
        {
            values[x][y] = 0;
        }
    }

    private static int CountDestoyedBomb()
    {
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (values[i][j] == 1)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    // 취소를 어떻게 하지...
    // 그전 데이터를 보관해두고 그걸 지우면서 pop하자.
    public static void Solve(int idx)
    {
        if (idx == PosN)
        {
            // 모든 위치에 폭탄 배치 완료
            MaxCount = Math.Max(MaxCount, CountDestoyedBomb());
            return;
        }

        // 1번 폭탄 결정
        // 타입별로 다 넣어보기(1, 2, 3번 타입)
        for (int j = 0; j < 3; j++)
        {
            List<(int, int)> changed = new List<(int, int)>();

            // 폭탄 위치 넣기
            Addbomb(j, posValues[idx].x, posValues[idx].y, changed);

            // 다음 위치 넣어보기
            Solve(idx + 1);

            // 이전에 넣은 폭탄 제거
            RemoveBomb(changed);
        }

        // 2번 폭탄 결정


        // 3번 폭탄 결정
    }

    public static void Main()
    {
        // Please write your code here.
        N = int.Parse(Console.ReadLine());
        MaxCount = 0;

        posValues = new List<PosData>();
        values = new List<List<int>>();

        for(int i = 0; i < N; i++)
        {
            values.Add(new List<int>());
            string[] input = Console.ReadLine().Split(' ');
            
            for (int j = 0; j < N; j++)
            {
                int cell = int.Parse(input[j]);
                values[i].Add(0);

                if (cell == 1)
                {
                    posValues.Add(new PosData(i, j));
                }
            }
        }

        PosN = posValues.Count;


        Solve(0); // 0부터 N - 1까지

        Console.Write(MaxCount);
    }
}