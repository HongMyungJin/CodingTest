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

        while (j >= 0 && datas[j] < key)
        {
            datas[j + 1] = datas[j];
            j--;
        }
        datas[j + 1] = key;
    }
}
int main() {

    int N, k = 0;
    cin >> N;
    cin >> k;
    vector<int> Datas;
    Datas.resize(N);

    for (int i = 0; i < N; i++)
        cin >> Datas[i];

    solution(Datas);
    cout << Datas[k - 1];

    return 0;
}