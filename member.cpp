#define _CRT_SECURE_NO_WARNINGS
#include "member.h"
#include "functions.h"
#include "fanPage.h"
#include <string.h>
#include <iostream>
using namespace std;

Member::Member(const char* name, const Date birthDay) : _dateOfBirth(birthDay)
{
	_memberName = new char[strlen(name) + 1];
	strcpy(_memberName, name);
}


Member:: ~Member()
{
	vector<Status*>::iterator itr = _memberStatus2.begin();
	vector<Status*>::iterator itrEnd = _memberStatus2.end();
	for (; itr != itrEnd; ++itr)
	{
		delete* itr;
	}
	delete[] _memberName;
}

// gets a ref to a status and adds its address to the member statuses arr.
void Member::addStatus(Status& status)
{
	Status* statusToAdd = new Status(status.getContent(), status.getDate(), status.getTime());
	_memberStatus2.push_back(statusToAdd);
}

void Member:: operator+=(Member& memberToAdd)
{
	addFriend(&memberToAdd);
}

bool Member:: operator>(const Member& other) const
{
	return getNumOfFriends() > other.getNumOfFriends();
}

int Member:: getNumOfStatuses()
{
	return _memberStatus2.size();
}

// add friendToAdd address to this members friends arr.
void Member::addFriend(Member* friendToAdd)
{
	vector<Member*>::iterator itr = _memberFriends2.begin();
	vector<Member*>::iterator itrEnd = _memberFriends2.end();
	vector<Member*>::iterator tmp = find(itr, itrEnd, friendToAdd);
	if (tmp != itrEnd)
		return;

	_memberFriends2.push_back(friendToAdd);
	friendToAdd->addFriend(this);
}

// removes the friendToRemove address from this member friends arr.
void  Member:: removeFriend(Member* friendToRemove)
{
	vector<Member*>::iterator itr = _memberFriends2.begin();
	vector<Member*>::iterator itrEnd = _memberFriends2.end();
	vector<Member*>::iterator tmp = find(itr, itrEnd, friendToRemove);
	if (tmp == itrEnd)
		return;
	_memberFriends2.erase(tmp); // add exeption if 
	friendToRemove->removeFriend(this);
}

// add the fanPageToAdd address to this member pages arr.
void Member::addPage(FanPage* fanPageToAdd)
{
	vector<FanPage*>::iterator itr = _memberFanPages2.begin();
	vector<FanPage*>::iterator itrEnd = _memberFanPages2.end();
	vector<FanPage*>::iterator tmp = find(itr, itrEnd, fanPageToAdd);
	if (tmp != itrEnd)
		return;

	_memberFanPages2.push_back(fanPageToAdd);
	fanPageToAdd->addFan(this);
}

// removes fanPageToRemove from this member pages arr.
void Member:: removePage(FanPage* fanPageToRemove)
{
	vector<FanPage*>::iterator itr = _memberFanPages2.begin();
	vector<FanPage*>::iterator itrEnd = _memberFanPages2.end();
	vector<FanPage*>::iterator tmp = find(itr, itrEnd, fanPageToRemove);
	if (tmp == itrEnd)
		return;
	_memberFanPages2.erase(tmp);
	fanPageToRemove->removeFan(this);
}

void Member::showAllStatus() const
{

	vector<Status*>::const_iterator itr = _memberStatus2.begin();
	vector<Status*>::const_iterator itrEnd = _memberStatus2.end();
	for (; itr != itrEnd; ++itr)
	{
		(*itr)->showStatus();
		cout << "\n---------------------\n";
	}
}

const char* Member:: getMemberName()
{
	return _memberName;
}

Date Member:: getMemberBirthDate() const
{
	return _dateOfBirth;
}

void Member::showAllFriends(bool withIndex)
{
	vector<Member*>::iterator itr = _memberFriends2.begin();
	vector<Member*>::iterator itrEnd = _memberFriends2.end();

	if (withIndex) {
		for (int i = 1; itr != itrEnd; ++itr, ++i)
			cout << i << ". " << (*itr)->getMemberName() << "\n";
	}
	else {
		for (; itr != itrEnd; ++itr)
			cout << (*itr)->getMemberName() << "\n";
	}
}

void Member::showAllFanpages(bool withIndex)
{
	vector<FanPage*>::iterator itr = _memberFanPages2.begin();
	vector<FanPage*>::iterator itrEnd = _memberFanPages2.end();
	if (withIndex) {
		for (int i = 1; itr != itrEnd; ++itr, ++i)
			cout << i << ". " << (*itr)->getPageName() << "\n";
	}
	else {
		for (; itr != itrEnd; ++itr)
			cout << (*itr)->getPageName() << "\n";
	}
}

// shows the last max 10 statuses of this member's friends.
void Member::showLatestFriendsStatus()
{
	vector<Member*>::iterator itr1 = _memberFriends2.begin();
	vector<Member*>::iterator itrEnd1 = _memberFriends2.end();
	vector<Status*>::const_iterator itr2;
	vector<Status*>::const_iterator itrEnd2;
	cout << _memberName << " friends latest statuses: \n\n";
	for (; itr1 != itrEnd1; ++itr1)
	{
		int numOfStatuses = (*itr1)->getNumOfStatuses();
		if (numOfStatuses == 0)
			continue;
		cout << (*itr1)->getName() << ":\n\n";

		itr2 = (*itr1)->_memberStatus2.begin();
		itrEnd2 = (*itr1)->_memberStatus2.end();

		for (; itr2 != itrEnd2; ++itr2)
		{
			(*itr2)->showStatus();
			cout << "\n---------------\n";
		}
	}

}

const char* Member:: getName() const
{
	return _memberName;
}

int Member::getNumOfFriends() const
{
	return _memberFriends2.size();
}

vector<Member*> const Member::getAllMembers()
{
	return _memberFriends2;
}