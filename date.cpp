#include "date.h"
#include <iostream>
using namespace std;

Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

int Date::getDay()
{
	return day;
}
int Date::getMonth()
{
	return month;
}
int Date::getYear()
{
	return year;
}


void Date::showDate() const
{
	cout << day << "." << month << "." << year;
}