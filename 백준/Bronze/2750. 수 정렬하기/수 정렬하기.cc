#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution(vector<int>& datas)
{
    for (int i = 1; i < datas.size(); i++)
    {
        int key = datas[i];
        int j = i - 1;

        while (j >= 0 && datas[j] > key)
        {
            datas[j + 1] = datas[j];
            j--;
        }
        datas[j + 1] = key;
    }
}
int main() {
    int n;
    vector<int> Datas;
    cin >> n;
    Datas.resize(n);

    for (int i = 0; i < n; i++)
        cin >> Datas[i];

    solution(Datas);
    for (int i : Datas)
        cout << i << "\n";
    return 0;
}