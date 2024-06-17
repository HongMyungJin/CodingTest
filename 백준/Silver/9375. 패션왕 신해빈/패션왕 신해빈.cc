#include <iostream>
#include <string>
#include <map>

int main()
{
    int CaseN;
    int N;
    // Type
    std::cin >> CaseN;

    for (int i = 0; i < CaseN; i++)
    {
        int total = 1;
        std::string Name;
        std::string Type;
        std::map<std::string, int> Values;

        std::cin >> N;
        for (int j = 0; j < N; j++)
        {
            std::cin >> Name;
            std::cin >> Type;
            if (Values.find(Type) == Values.end())
                Values.insert(std::make_pair(Type, 1));
            else
                Values[Type]++;
        }
        for (std::pair<std::string, int> value : Values)
            total *= (value.second + 1);

        std::cout << total - 1 << std::endl;
    }
    return 0;
}