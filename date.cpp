#define _CRT_SECURE_NO_WARNINGS
#include "date.h"
#include <ctime>
#include <iostream>
using namespace std;

Date::Date()
{
	time_t now = time(0);
	tm* localtm = localtime(&now);
	_day = localtm->tm_mday;
	_month = localtm->tm_mon + 1;
	_year = localtm->tm_year + 1900;
}

Date::Date(int day, int month, int year)
{
	_day = day;
	_month = month;
	_year = year;
}

int Date::getDay() const
{
	return _day;
}
int Date::getMonth() const
{
	return _month;
}
int Date::getYear() const
{
	return _year;
}


void Date::showDate() const
{
	cout << _day << "." << _month << "." << _year;
}