using System;
using System.Collections.Generic;
public class Codetree
{  
    private static List<int> _values;
    private static int _solveN;
    private static int _N;

    private static bool Check()
    {
        List<int> nums = new List<int>{0, 0, 0, 0};

        int n = 1;
        int preValue = _values[0]; // 첫번째 값
        for(int i = 1; i < _values.Count; i++)
        {
            if (_values[i] == preValue)
            {
                n++;
            }
            else
            {
                if (n != preValue)
                {
                    return false;
                }
            }
            preValue = _values[i];
        }

        // 개수가 1개일 경우 1이 아니라면 false
        if (_values.Count == 1 && _values[0] != 1)
        {
            return false;
        }

        return true;
    }
    private static void Solve(int count)
    {
        // N개를 다 채웠으면(N개 이후 1만큼 더 들어왔으면)
        if (count == _N + 1)
        {
            if(Check())
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
