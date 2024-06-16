#include <iostream>
#include <string>

bool CheckPattern_FileName(std::string InputPattern, std::string InputFileName)
{
    int index = InputPattern.find('*'); // 입력된 파일 이름 개수만큼
   std::cin >> InputFileName;

   if (InputPattern.length() - 1 > InputFileName.length())
       return false;

   for (int i = 0; i < index; i++)    // * 이전
       if (InputFileName[i] != InputPattern[i])
           return false;

   for (int i = 0; i < InputPattern.length() - (index + 1); i++)    // * 이후
       if ((InputFileName.length() - 1 - i < 0) || (InputFileName[InputFileName.length() - 1 - i] != InputPattern[InputPattern.length() - 1 - i])) // 끝부터 검사
           return false;
   return true;
}
int main()
{
    int N;
    std::string InputPattern;
    std::string InputFileName;

    std::cin >> N;
    std::cin >> InputPattern;

    for (int i = 0; i < N; i++)
    {
        if (CheckPattern_FileName(InputPattern, InputFileName))
            std::cout << "DA\n";
        else
            std::cout << "NE\n";
    }
    return 0;
}