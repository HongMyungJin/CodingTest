#include <iostream>

using namespace std;

int main()
{
	unsigned int hour, minute, cookminute = 0;

	cin >> hour >> minute;
	cin >> cookminute;
	
	cout << (hour + (cookminute + minute) / 60) % 24  << " " << (minute + cookminute) % 60 << endl;
}