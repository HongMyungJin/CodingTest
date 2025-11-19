#include <iostream>
#include <vector>
using namespace std;

void RemoveVector(vector<int>& inputs, int last, int continues)
{
    for (int i = last; i < last + continues; i++)
    {
        inputs[i] = 0;
    }
}
int N, M;
int main() {
    // Please write your code here.
    cin >> N >> M;

    vector<int> inputs(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> inputs[i];
    }
    bool remove = true;

    while(remove)
    {
        remove = false;
        int size = inputs.size();
        int continues = 1;
        int cur = inputs[size - 1];
        for (int t = size - 2; t >= 0; t--)
        {
            if (cur == inputs[t]) // 이전꺼랑 같은거
            {
                continues++;

                if (t == 0 && continues >= M)
                {
                    RemoveVector(inputs, t, continues);
                    remove = true;
                }
            }
            else // 이전꺼랑 다른거
            {
                if (continues >= M) // 연속 개수 넘어감
                {
                    // 지우기
                    RemoveVector(inputs, t + 1, continues);
                    remove = true;
                }
                continues = 1;
            }
            cur = inputs[t];
        }

        vector<int> newInputs;
        
        int curIdx = 0;
        for (int i = 0; i < inputs.size(); i++)
        {
            if (inputs[i] != 0)
                newInputs.emplace_back(inputs[i]);
        }
        inputs = newInputs;
    }

    cout << inputs.size() << '\n';
    for (int i = 0; i < inputs.size(); i++)
    {
        cout << inputs[i] << '\n';
    }


    return 0;
}