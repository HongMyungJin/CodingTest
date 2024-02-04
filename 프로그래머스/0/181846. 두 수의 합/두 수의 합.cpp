#include <string>
#include <vector>

using namespace std;

string solution(string a, string b) {
    int aLength = a.length() - 1;
    int bLength = b.length() - 1;

    string answer = "";
    int idx = 0;
    int plus = 0;
    while (1)
    {
        if (aLength >= 0 && bLength >= 0)
            answer.insert(0, 1, a[aLength--] + b[bLength--] - '0' + plus);
        else if (aLength >= 0)
            answer.insert(0, 1, a[aLength--] + plus);
        else if (bLength >= 0)
            answer.insert(0, 1, b[bLength--] + plus);
        else
        {
            if(plus == 1)
                answer.insert(0, 1, '1');
            break;
        }
        plus = 0;

        if (answer[0] > '9')
        {
            answer[0] -= 10;
            plus = 1;
        }
        idx++;
    }

    return answer;
}