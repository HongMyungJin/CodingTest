#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string letter) {
    string answer = "";
    string buff = "";
    
    vector mos = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    vector<string> datas;
    istringstream iss(letter);
    while(getline(iss, buff, ' '))
        datas.emplace_back(buff);

    for(string& data : datas)
        answer += 'a' + find(mos.begin(), mos.end(), data) - mos.begin();
    return answer;
}