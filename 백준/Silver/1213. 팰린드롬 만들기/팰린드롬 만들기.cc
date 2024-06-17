#include <iostream>

int main()
{
    std::string input;
    std::string output;
    int Alpha[26] = {0, };
    char mid = 0;
    int OddFlag = 0;
    std::cin >> input;

    // 알파벳 개수 보관
    for (char ch : input)
        Alpha[ch - 'A']++;

    // Z부터 먼저 붙인다.
    for (int i = 'Z'; i >= 'A'; i--)
    {
        if (Alpha[i - 'A'] > 0) // 알파벳이 존재
        {
            if (Alpha[i - 'A'] % 2 != 0) //  홀수개
            {
                mid = char(i);
                Alpha[i - 'A']--; // 홀수 -> 짝수
                if (++OddFlag == 2)// 홀수 증가 후 확인(홀수가 2개 이상이면 팰랜드롬 만들지X)
                    break;
            }
            for (int t = 0; t < Alpha[i - 'A']; t += 2)
            {
                output = char(i) + output; // 앞에 붙이기
                output += char(i); // 뒤에 붙이기
            }
        }
    }

    if (mid >= 'A')
        output.insert(output.begin() + output.length() / 2, mid);
    if (OddFlag == 2)
        std::cout << "I'm Sorry Hansoo" << std::endl;
    else
        std::cout << output << std::endl;
}