#include <iostream>
#include <string.h>
#include <map>
#include <unordered_map>

int main()
{
    int N;
    std::map<char, int> FirstNames;
    std::string input;

    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> input;
        std::map<char, int>::iterator it = FirstNames.find(input[0]);
        if (FirstNames.end() == it)
            FirstNames.insert(std::make_pair(input[0], 1));
        else
            ++(it->second);
    }

    bool Check = false;
    for (std::pair<char, int> Name : FirstNames)
    {
        if (Name.second >= 5)
        {
            Check = true;
            std::cout << Name.first;
        }
    }
    if(!Check)
        std::cout << "PREDAJA" << std::endl;


    return 0;
}