#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    string data = "";
    int answer = 0;
    for (int i = 0; i < my_string.length(); i++)
    {
        if (isdigit(my_string[i]))
        {
            data += my_string[i];
            if(i == my_string.length() - 1)
                answer += stoi(data);
        }
        else if (data != "")
        {
            answer += stoi(data);
            data = "";
        }

    }
    return answer;
}