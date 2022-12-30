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
	bool addPage(FanPage& newPage)noexcept(false);
	void addStatusToMember(Member& member, Status& status) noexcept(false);
	void addStatusToFanPage(FanPage& fanPage, Status& status) noexcept(false);
	void showMembers(bool index) const;
	void showPages(bool index) const;
	const std::vector<Member*> getAllMembers() const; // not used
	const std::vector<FanPage*>  getAllFanPages() const; // not used
	bool isNameMemberUsed(Member& member) const;
	bool isNameFanPageUsed(FanPage& fanPage) const;
	void removeMemberFromPage(FanPage& page, Member& member) noexcept(false);
	void cancelFriendship(Member& mem1, Member& mem2) noexcept(false);
	void addMemberToPage(FanPage& page, Member& member) noexcept(false);
	FanPage* findFanPage(int index)noexcept(false);
	FanPage* findFanPage(FanPage& fanPage); 
	Member* findMember(int index) noexcept(false);
	Member* findMember(Member& member);
	void makeFriends(Member& member1, Member& member2) noexcept(false);
	void showMemberFriend(Member& member) noexcept(false);
	void showPageFans(FanPage& fPage) noexcept(false);

};
#endif // !FACEBOOK_H

