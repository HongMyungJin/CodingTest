#include <iostream>
#include <string>

using namespace std;
int main()
{
	string Subject;
	double Credit;
	std::string Score;
	int CreditSubject = 0;
	double TotalScore = 0.f;
	for (int i = 0; i < 20; i++)
	{
		cin >> Subject >> Credit >> Score;
		if (Score == "F")
			CreditSubject += Credit;
		else if (Score != "P")
		{
			TotalScore += Credit * (4.f - (Score[0] - 'A') + (Score[1] == '+' ? 0.5f : 0.f));
			CreditSubject += Credit;
		}
	}

	cout.precision(7);
	cout << TotalScore / CreditSubject << endl;
}
