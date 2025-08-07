#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, bool> values;

	values["ChongChong"] = true;

	int n;

	cin >> n;

	int num = 1;
	for (int i = 0; i < n; i++)
	{
		string A, B;

		cin >> A >> B;

		if (values[A] == true)
		{
			values[B] == false ? values[B] = true, num++ : values[B] = true;
		}
		else if (values[B] == true)
		{
			values[A] == false ? values[A] = true, num++ : values[A] = true;
		}
	}
	cout << num;

	return 0;
}