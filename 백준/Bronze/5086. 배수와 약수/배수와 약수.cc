#include <iostream>
#include <string>

using namespace std;

string solution(int n1, int n2) {

    return (n2 % n1 == 0) ? "factor" : (n1 % n2 == 0) ? "multiple" : "neither";
}

int main()
{
    int n1, n2;
    while(1)
    {
        cin >> n1 >> n2;
        if ((n1 == 0 && n2 == 0))
            break;
        cout << solution(n1, n2) << endl;
    }
    return 0;
}