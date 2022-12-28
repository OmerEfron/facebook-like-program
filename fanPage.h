#ifndef FAN_PAGE_H
#define FAN_PAGE_H
#include "status.h"
#include "member.h"
#include <vector>
class Member;

class FanPage {
private:
	char* _pageName;
	std::vector <Member*> _pageFans2;
	std::vector<Status*> _pageStatus2;
public:
	FanPage(const char* pageName);
	~FanPage();
	const char* getPageName();
	void addFan(Member* member);
	void removeFan(Member* member);
	void showAllFans(bool withIndex);
	void showAllStatus();
	void addStatus(Status&);
	int getNumOfFans()const;
	std::vector<Member*> const getPageFans();
	bool operator>(const FanPage& other)const;

};
#endif // !FAN_PAGE_H
