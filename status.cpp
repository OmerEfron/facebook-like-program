#define _CRT_SECURE_NO_WARNINGS


#include "status.h"
#include <string.h>
#include <iostream>
using namespace std;

Status::Status(const char* content, const Date date, const Time time) : _statusDate(date), _statusTime(time)
{
	_content = new char[strlen(content) + 1];
	strcpy(_content, content);
}

Status::~Status()
{
	delete[] _content;
}


const char* Status:: getContent() const
{
	return _content;
}
const Date Status::getDate() const
{
	return _statusDate;
}
const Time Status::getTime() const
{
	return _statusTime;
}

void Status:: showStatus() const
{
	_statusDate.showDate();
	cout << "\n";
	_statusTime.showHour();
	cout << "\n"<< _content;
}
