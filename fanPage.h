#ifndef FAN_PAGE_H
#define FAN_PAGE_H
#include "status.h"
#include "member.h"
#include <vector>
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
	std::vector <Member*> _pageFans2;

public:
	FanPage(const char* pageName);
	~FanPage();
	const char* getPageName();
	void addFan(Member* member);
	std::vector<Member*>::iterator isFan(Member* fan);
	void removeFan(Member* member);
	void showAllFans(bool withIndex);
	void showAllStatus();
	void addStatus(Status&);
	int getNumOfFans();
	std::vector<Member*> const getPageFans();
	bool operator>(const FanPage& other)const;

};
#endif // !FAN_PAGE_H
