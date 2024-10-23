#include <string>
#include <vector>

using namespace std;

long long solution(string numbers) {
    string numData;
    vector<string> numberDatas = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    int n = 0;
    while (n < numbers.length())
    {
        for (int i = 0; i < numberDatas.size(); i++)
        {
            string data = numbers.substr(n, numberDatas[i].length());
            if (data == numberDatas[i])
            {
                numData += '0' + i;
                n += numberDatas[i].length();
            }
        }
    }

    return stoll(numData);
}