#include <iostream>
#include <vector>
#include <string>
using namespace std;

int MovieName(int n)
{   
    unsigned long long value = 666;
    int dataN = 0;
    while (1)
    {
        if (to_string(value).find("666") != -1)
            dataN++;
        if (dataN == n)
            return value;
        value++;
    }
} 

int main()
{
    int n;
    cin >> n;

    cout << MovieName(n);
    return 0;
} 
