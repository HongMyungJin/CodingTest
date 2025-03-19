#include <iostream>
#include <vector>
#include <algorithm>
#define INCREASE_VALUE 6

void CalculateFractions(int n)
{
    std::vector<int> fraction;
    fraction.resize(2);

    // 1. 인덱스 번호 구하기
    // 2. 몇 번째 행인지 구하기(제일 큰 수)
    // 3. 몇 번째 열인지 구하기(분수로 사용할 수)
    
    int totalIndex = 0;
    int row = 0;
    int col = 0;
    while (totalIndex < n) // 누적 인덱스 값이 실제 인덱스보다 크거나 같아지면(행 열 결정)
    {
        row++; // 행 개수 증가(1, 2, 3, 4.. )
        totalIndex += row; // 열 개수 증가(1, 1 + 2, 1 + 2 + 3, 1 + 2 + 3 + 4.. ) 총 누적 인덱스
    }
    // 전에까지 토탈: totalIndex - row
    col = n - (totalIndex - row);
    
    int numerator = 0;// 분자
    int denominator = 0; // 분모
    if (row % 2 == 0) // 짝수 - 증가
    {
        numerator = col;
        denominator = row - (col - 1);
    }
    else // 홀수 - 감소
    {
        numerator = row - (col - 1);
        denominator = col;
    }
    std::cout << numerator << "/" << denominator;
}

int main()
{
    int n;
    std::cin >> n;
   
    CalculateFractions(n);
    return 0;
}