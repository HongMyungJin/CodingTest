#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	list<char> wordList;
	string word;
	cin >> word;

	for (size_t i = 0; i < word.length(); i++)
	{
		wordList.emplace_back(word[i]);
	}
	list<char>::iterator it = wordList.end();

	int n;
	char input[2];
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input[0];
		switch (input[0])
		{
			case 'L':
			{
				if (it != wordList.begin())
					--it;
			}
				break;
			case 'D':
			{
				if (it != wordList.end())
					++it;
			}
				break;
			case 'B':
			{
				if (it != wordList.begin())
				{
					it = wordList.erase(--it);
				}
			}
				break;
			case 'P':
			{
				cin >> input[1];

				wordList.insert(it, input[1]);
			}

				break;
		}
	}


	for (list<char>::iterator it = wordList.begin(); it != wordList.end(); it++)
	{
		cout << *it;
	}
}