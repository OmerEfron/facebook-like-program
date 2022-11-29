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
	//listOfStatuses _memberLatestFriendsStatus;
	Member** _memberFriends;
	FanPage** _memberFanPages;
public:
	Member(char* name, Date birthDay);
	~Member();
	int isFriend(Member* member);
	int isFan(FanPage* fanPage);
	void addFriend(Member* friendToAdd);
	void removeFriend(Member* friendToRemove);
	void addPage(FanPage* fanPageToAdd);
	void removePage(FanPage* fanPageToRemove);
	void addStatus(Status& statusToAdd);
	void showAllStatus();
	void showLatestFriendsStatus();
};
#endif // !MEMBER_H