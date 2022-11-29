#ifndef FAN_PAGE_H
#define FAN_PAGE_H
#include "status.h"
#include "member.h"

class FanPage {
private:
	char* _pageName;
	int _numOfStatus;
	int _numOfFans;
	int _statusesPhySize;
	int _fansPhySize;
	Status** pageStatuses;
	//Member** pageFans;
//public:

};
#endif // !FAN_PAGE_H
