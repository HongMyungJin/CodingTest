#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> strArr) {
    unordered_multimap<int, string> hashmap;
    std::vector<int> keyValues;
    for (int i = 0; i < strArr.size(); i++)
    {
        hashmap.insert(std::pair<int, string>(strArr[i].length(), strArr[i]));

        if (keyValues.end() == find(keyValues.begin(), keyValues.end(), strArr[i].length()))
            keyValues.emplace_back(strArr[i].length());
    }
    int max = 0;
    for (int i = 0; i < keyValues.size(); i++)
    {
        int hashmapN = hashmap.count(keyValues[i]);
        if (max < hashmapN)
            max = hashmapN;
    }
    return max;
}