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
	Status(const char*,const  Date date,const Time time);
	Status(Status&) = delete;
	const char* getContent() const;
	const Date getDate() const;
	const Time getTime() const;
	void showStatus() const;
	~Status();
};

#endif // !STATUS_H