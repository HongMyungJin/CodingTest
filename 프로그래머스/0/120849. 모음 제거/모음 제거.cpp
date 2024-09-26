#include <string>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    char datas[] = {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i < 5; i++)
            my_string.erase(remove(my_string.begin(), my_string.end(), datas[i]), my_string.end());
    return my_string;
}