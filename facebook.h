#ifndef FACEBOOK_H
#define FACEBOOK_H


#include "member.h"
#include "fanPage.h"
#include <vector>



class Facebook {
private:
	std::vector<Member*> _members;
	std::vector <FanPage*> _fanPages;

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
	std::vector<Member*> const getAllMembers();
	const std::vector<FanPage*>  getAllFanPages();
	bool isNameMemberUsed(Member& member);
	bool isNameFanPageUsed(FanPage& fanPage);
	void removeMemberFromPage(FanPage& page, Member& member);
	void cancelFriendship(Member& mem1, Member& mem2);
	void addMemberToPage(FanPage& page, Member& member);
	FanPage* findFanPage(int index);
	Member* findMember(int index);
};
#endif // !FACEBOOK_H

