#include <iostream>
#include <vector>
#include <string>
using namespace std;

string solution(int n) {

    int sum = 0;
    std::vector<int> data;

    string result = "";
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            data.emplace_back(i);
            sum += i;
        }
    }
    if (sum == n)
    {
        result += to_string(sum) + " = ";
        for (int i = 0; i < data.size(); i++)
        {
            result += to_string(data[i]);
            if (i != data.size() - 1)
                result += " + ";
        }
    }
    else
    {
        result = to_string(n) + " is NOT perfect.";
    }
    return result;
}

int main()
{
    int n;

    while (1)
    {
        cin >> n;
        
        if (n == -1)
            break;
        cout << solution(n) << endl;
    }
    return 0;
}