#define _CRT_SECURE_NO_WARNINGS


#include "status.h"
#include <string.h>
#include <iostream>
using namespace std;

Status::Status(char* content, Date date, Time time) : _statusDate(date), _statusTime(time)
{
	_content = new char[strlen(content) + 1];
	strcpy(_content, content);
}

Status::~Status()
{
	delete[] _content;
}
