#ifndef MEMBER_H
#define MEMBER_H


#include "date.h"
#include "status.h"
#include "fanPage.h"
#include "listOfStatus.h"
const int NOT_FOUND = -1;

class FanPage;

class Member {

private:
	char* _memberName;
	Date _dateOfBirth;
	int _numOfStatus, _numOfFriends, _numOfFanPages;
	int _statusesPhySize, _friendsPhySize, fanPagesPhySize;
	Status** _memberStatuses;
	Member** _memberFriends;
	FanPage** _memberFanPages;
public:
	Member(const char* name, const Date birthDay);
	Member(const Member&) = delete;
	~Member();
	int isFriend(Member* member);
	int isFan(FanPage* fanPage);
	void addToLatestStatuses(Status& status);
	void addToFriendsLatestStatuses(Status& status);
	void addFriend(Member* friendToAdd);
	void removeFriend(Member* friendToRemove);
	void addPage(FanPage* fanPageToAdd);
	void removePage(FanPage* fanPageToRemove);
	void addStatus(Status& statusToAdd);
	const char* getMemberName();
	int getNumOfStatuses();
	const Status** getStatuses() const;
	const char* getName() const;
	Date getMemberBirthDate() const;
	void showAllStatus() const;
	void showAllFanpages(bool withIndex);
	void showAllFriends(bool withIndex);
	void showLatestFriendsStatus();
	int getNumOfFriends();
	Member** const getAllMembers();
	void operator+=(Member& memberToAdd);
	bool operator>(const Member& other) const;
};
#endif // !MEMBER_H