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
	Member(char* name, Date birthDay);
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
	void showAllStatus() const;
	void showAllFanpages();
	void showAllFriends();
	void showLatestFriendsStatus();
};
#endif // !MEMBER_H