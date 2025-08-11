#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct Time
{
	int hour;
	int min;
};
int main()
{
	Time sTime[3];
	map<string, int> values;
	for (int i = 0; i < 3; i++)
	{
		string time;
		cin >> time;
		sTime[i].hour = stoi(time.substr(0, 2));
		sTime[i].min = stoi(time.substr(3, 2));
	}

	int attend = 0;
	while (!cin.eof())
	{
		string time, name;

		cin >> time >> name;

		if (time.empty() || name.empty())
			break;

		int hour = stoi(time.substr(0, 2));
		int min = stoi(time.substr(3, 2));

		int count = values.count(name);
		if (count == 0)
		{
			if (sTime[0].hour > hour || ((sTime[0].hour == hour) && (sTime[0].min >= min)))
			{
				++values[name];
			}
		}
		else if (values[name] > 0)
		{
			if ((sTime[1].hour < hour || (sTime[1].hour == hour && sTime[1].min <= min)) &&
				(sTime[2].hour > hour || (sTime[2].hour == hour && sTime[2].min >= min))
				)
			{
				values[name] = -1;
				++attend;
			}
		}
	}

	cout << attend;

	return 0;
}