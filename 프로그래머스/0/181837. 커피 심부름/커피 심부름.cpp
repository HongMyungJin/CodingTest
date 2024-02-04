#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) {
    int total = 0;
    for(int i = 0; i < order.size(); i++)
    {
       if ("anything" == order[i] || order[i].find("american") != string::npos)
            total += 4500;
        else
            total += 5000;
    }
        
    return total;
}