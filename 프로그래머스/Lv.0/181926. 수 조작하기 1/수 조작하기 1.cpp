#include <string>
#include <vector>

using namespace std;

int solution(int n, string control) {
    
    for (char st : control)
    {
        switch (st)
        {
        case 'w':
                n += 1;
            break;
        case 's':
                n -= 1;
            break;
        case 'd':
                n += 10;
            break;
        case 'a':
                n -= 10;
            break;
        }
    }
    return n;
}