#ifndef MEMBER_H
#define MEMBER_H


#include "date.h"
#include "status.h"
#include "fanPage.h"
#include <vector>
const int NOT_FOUND = -1;

class FanPage;

class Member {

private:
	char* _memberName;
	Date _dateOfBirth;
	std::vector<Status*> _memberStatus2;
	std::vector<Member*> _memberFriends2;
	std::vector<FanPage*> _memberFanPages2;
public:
	Member(const char* name, const Date birthDay);
	Member(const Member&) = delete;
	~Member();
	
	
	void addFriend(Member* friendToAdd);
	void removeFriend(Member* friendToRemove);
	void addPage(FanPage* fanPageToAdd);
	void removePage(FanPage* fanPageToRemove);
	void addStatus(Status& statusToAdd);
	const char* getMemberName();
	int getNumOfStatuses();
	const char* getName() const;
	Date getMemberBirthDate() const;
	void showAllStatus() const;
	void showAllFanpages(bool withIndex);
	void showAllFriends(bool withIndex);
	void showLatestFriendsStatus();
	int getNumOfFriends()const;
	std::vector<Member*> const getAllMembers();
	void operator+=(Member& memberToAdd);
	bool operator>(const Member& other) const;
};
#endif // !MEMBER_H