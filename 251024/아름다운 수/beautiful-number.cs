using System;
using System.Collections.Generic;
public class Codetree
{
    private static List<int> _values;
    private static int _solveN;
    private static int _N;

    private static bool Check()
    {
        // 개수만큼 있는지 테스트 1이면 1개 2이면 2개
        int n = 0;
        int preValue = _values[0];
        for (int i = 0; i < _N; i++)
        {
            // 이전값이랑 현재값이랑 같을 경우 증가
            if (preValue == _values[i])
            {
                n++;

                if (_values[i] == n)
                {
                    n = 0; // 초기화
                }
                else if (i == _N - 1) // 마지막일 경우
                {
                    return false;
                }
            }
            else // 다를 경우
            {
                // 이전 값이랑 개수가 다르다면
                if (preValue != n)
                {
                    return false;
                }

                n = 1;
            }

            preValue = _values[i];
        }


        return true;
    }
    private static void Solve(int count)
    {
        // N개를 다 채웠으면(N개 이후 1만큼 더 들어왔으면)
        if (count == _N + 1)
        {
            if (Check())
            {
                _solveN++; // 개수 증가
            }
            return; // 이번 종료
        }

        for (int i = 1; i <= 4; i++)
        {
            // 1, 2, 3, 4 순차적으로 넣고
            _values.Add(i);

            Solve(count + 1); // 재귀함수로 돌리기~

            // 이전 단계로 돌리기
            _values.RemoveAt(_values.Count - 1);
        }
    }

    public static void Main()
    {
        // Please write your code here.
        // 모든 경우의 수를 체크해서 만약에 해당하면 출력하자.
        _solveN = 0;
        _values = new List<int>();
        _N = int.Parse(Console.ReadLine());
        Solve(1);

        Console.Write(_solveN);
    }
}
