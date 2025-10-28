using System;
using System.Collections.Generic;

public class Codetree
{
    private static int N, M, K;
    private static int Max;

    private static List<int> MoveData = new();

    private static List<int> Moves = new();


    // 특정 값 이동

    // 말 번호
    private static void Solve(int count, int score)
    {
        if (count == N)
        {
            Max = score > Max ? score : Max;
            return;
        }

        bool isMove = false;

        // K번째 전까지 말
        for (int i = 0; i < K; i++)
        {
            int preMove = Moves[i];

            if (preMove >= M)// 다음으로 넘어감. 이미 처리된 말에 해당
            {
                continue;
            }

            ///////// 여기까지는 이동x
            /// 이동함.
            isMove = true;

            bool addScore = false;

            Moves[i] += MoveData[count];

            if (preMove < M && Moves[i] >= M)
            {
                Moves[i] = M;
                addScore = true;
                ++score;
            }
            // 다음 턴
            // 횟수, 스코어...
            Solve(count + 1, score);

            if (addScore)
            {
                --score;
            }

            Moves[i] = preMove;
        }

        if (isMove)
        {
            Solve(count + 1, score);
        }
    }
    public static void Main()
    {
        // Please write your code here.
        Max = 0;

        string[] inputs = Console.ReadLine().Split(' ');
        string[] inputNums = Console.ReadLine().Split(' ');
        N = int.Parse(inputs[0]);
        M = int.Parse(inputs[1]);
        K = int.Parse(inputs[2]);

        // N: 주어진 숫자의 개수(이동 수들의 개수)
        // M: M 현재 판의 도착 지점
        // K: 말의 수

        // N회 반복
        for (int i = 0; i < N; i++)
        {
            MoveData.Add(int.Parse(inputNums[i]));
        }

        for (int i = 0; i < K; i++)
        {
            Moves.Add(1);
        }

        Solve(0, 0);

        Console.Write(Max);
    }
}