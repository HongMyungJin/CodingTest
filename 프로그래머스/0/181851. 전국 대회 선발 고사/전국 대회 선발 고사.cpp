#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    map<int, int> rankData;
    for (int i = 0; i < rank.size(); i++)
    {
        if (attendance[i])
            rankData.insert({rank[i], i});
    }
    
    int rankValue[3];
    map<int, int>::iterator i = rankData.begin();
    for(int t = 0; t < 3; t++, i++)
        rankValue[t] = i->second;
    
    return rankValue[0] * 10000 + rankValue[1] * 100 + rankValue[2];
}