#ifndef FACEBOOK_H
#define FACEBOOK_H


#include "member.h"
#include "fanPage.h"
#include "memberException.h"
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
	void addMember(Member& newMember) noexcept(false);
	bool addPage(FanPage& newPage);
	void addStatusToMember(Member& member, Status& status);
	void showMembers() const;
	void showPages() const;
	const std::vector<Member*> getAllMembers() const;
	const std::vector<FanPage*>  getAllFanPages() const;
	bool isNameMemberUsed(Member& member) const;
	bool isNameFanPageUsed(FanPage& fanPage) const;
	void removeMemberFromPage(FanPage& page, Member& member);
	void cancelFriendship(Member& mem1, Member& mem2);
	void addMemberToPage(FanPage& page, Member& member);
	FanPage* findFanPage(int index);
	FanPage* findFanPage(FanPage& fanPage);
	Member* findMember(int index);
	Member* findMember(Member& member);
	void makeFriends(Member& member1, Member& member2);
};
#endif // !FACEBOOK_H

