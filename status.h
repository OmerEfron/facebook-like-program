#ifndef STATUS_H
#define STATUS_H

#include <time.h>
#include "date.h"
#include "time.h"
class Status
{
private:
	Date _statusDate;
	Time _statusTime;
	char* _content;

public:
	Status(char*, Date date, Time time);
	~Status();
};

#endif // !STATUS_H