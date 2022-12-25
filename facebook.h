#ifndef FACEBOOK_H
#define FACEBOOK_H


#include "member.h"
#include "fanPage.h"
#include <vector>



class Facebook {
private:
	int _numOfMembers, _numOfPages, _membersPhySize, _pagesPhySize;
	Member** _members;
	std::vector<Member*> _members2;
	FanPage** _fanPages;
	std::vector <FanPage*> _fanPages2;

public:
	Facebook();
	Facebook(const Facebook&) = delete;
	~Facebook();
	int getNumOfMembers() const;
	int getNumOfPages() const;
	bool addMember(Member& newMember);
	bool addPage(FanPage& newPage);
	void showMembers() const;
	void showPages() const;
	Member ** const getAllMembers();
	std::vector<FanPage*> const getAllFanPages();
	bool isNameMemberUsed(Member& member);
	bool isNameFanPageUsed(FanPage& fanPage);

};
#endif // !FACEBOOK_H

