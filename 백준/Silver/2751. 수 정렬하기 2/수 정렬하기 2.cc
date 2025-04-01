#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Merge(vector<int>& arr, int Left, int mid, int Light)
{
    vector<int> temp;
    int i = Left;
    int j = mid + 1;

    while (i <= mid && j <= Light)
    {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);

    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= Light) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[Left + k] = temp[k];

}

void MergeSort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}
int main() {

    int N, k = 0;
    cin >> N;

    vector<int> Datas;
    Datas.resize(N);

    for (int i = 0; i < N; i++)
        cin >> Datas[i];

    MergeSort(Datas, 0, Datas.size() - 1);
    for (int i = 0; i < N; i++)
        cout << Datas[i] << "\n";

    return 0;
}