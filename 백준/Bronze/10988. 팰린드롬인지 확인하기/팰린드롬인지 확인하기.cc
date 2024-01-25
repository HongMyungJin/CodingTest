#include <iostream>
#include <string>

using namespace std;
int main()
{
	string Word;
	cin >> Word;

	for (int i = 0; i < Word.length() / 2; i++)
	{
		if (Word[i] != Word[Word.length() - i - 1])
		{
			cout << 0 << endl;
			return 0;
		}
	}
	cout << 1 << endl;
}