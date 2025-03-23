#include<iostream>
#include<math.h>
using namespace std;
void Prime_Factor(int* N)
{
	bool Pass = false;
	for (int i = 2; i <= (int)sqrt(*N); i++)
	{
		if ((*N) % i == 0)
		{
			Pass = true;
				cout << i << endl;
				(*N) /= i;
				return;
			
		}
	}
	if (!Pass)
	{

		if((*N) != 1)
			cout << (*N) << endl;
		(*N) = 0;
		
	}
}
int main()
{
	int N;
	cin >> N;

	while (N != 0) { Prime_Factor(&N); };
}