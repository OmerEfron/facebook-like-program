#ifndef FAN_PAGE_H
#define FAN_PAGE_H
#include "status.h"
#include "member.h"

class Member;

class FanPage {
private:
	char* _pageName;
	int _numOfStatus;
	int _numOfFans;
	int _statusesPhySize;
	int _fansPhySize;
	Status** _pageStatuses;
	Member** _pageFans;
public:
	FanPage(char* pageName);
	~FanPage();
	void addFan(Member* member);
	int isFan(Member* fan);
	void removeFan(Member* member);

};
#endif // !FAN_PAGE_H
