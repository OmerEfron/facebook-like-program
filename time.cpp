#include "time.h"
#include <iostream>
using namespace std;

Time::Time(int h, int m)
{
	hour = h;
	minutes = m;
}
int Time::getHours()
{
	return hour;
}
int Time::getMinutes()
{
	return minutes;
}

void Time::showHour() const
{
	cout << hour << ":" << minutes;
}