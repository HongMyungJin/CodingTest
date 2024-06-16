#include <iostream>
#include <string>
int main()
{
    std::string input;
    std::getline(std::cin, input);

    for (char& ch : input)
    {
        if (std::isalpha(ch))
        {
            if ((std::isupper(ch) && (ch + 13) > 'Z') || (std::islower(ch) && (ch + 13) > 'z'))
                ch -= 13;
            else
                ch += 13;
        }
    }
    std::cout << input;
    return 0;
}