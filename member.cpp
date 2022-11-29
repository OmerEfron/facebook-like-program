#define _CRT_SECURE_NO_WARNINGS
#include "member.h"
#include "functions.h"
#include "fanPage.h"
#include <string.h>
#include <iostream>
using namespace std;

Member::Member(char* name, Date birthDay) : _dateOfBirth(birthDay)
{
	_memberName = new char[strlen(name) + 1];
	strcpy(_memberName, name);
	_numOfStatus = _numOfFriends = _numOfFanPages = 0;
	_statusesPhySize = _friendsPhySize = fanPagesPhySize = 1;
	_memberStatuses = new Status *[1];
	_memberFriends = new Member * [1];
	_memberFanPages = new FanPage * [1];
}

Member:: ~Member()
{
	delete _memberName;
	//for (int i = 0; i < _numOfStatus; i++)
		//delete _memberStatuses[i];
	delete[] _memberStatuses;
	delete[] _memberFriends;
	delete[] _memberFanPages;
}

void Member::addStatus(Status& statusToAdd)
{
	if (_numOfStatus == _statusesPhySize)
	{
		_statusesPhySize *= 2;
		_memberStatuses = (Status**)myrealloc(_memberStatuses, _numOfStatus, _statusesPhySize, sizeof(Status*));
	}
	_memberStatuses[_numOfStatus] = &statusToAdd;
	_numOfStatus++;

	// ADD TO LATEST STATUSES
}

int Member::isFriend(Member* member) // returns the index of the friend if found, NOT_FOUND if not.
{
	for (int i = 0; i < _numOfFriends; i++)
		if (member == _memberFriends[i])
			return i;
	return NOT_FOUND;
}

void Member::addFriend(Member* friendToAdd)
{
	if (this->isFriend(friendToAdd) >= 0)
		return;
	if (_numOfFriends == _friendsPhySize)
	{
		_friendsPhySize *= 2;
		_memberFriends = (Member**)myrealloc(_memberFriends, _numOfFriends, _friendsPhySize, sizeof(Member*));
	}
	_memberFriends[_numOfFriends] = friendToAdd;
	_numOfFriends++;
	friendToAdd->addFriend(this);
}
void  Member:: removeFriend(Member* friendToRemove)
{
	int i = this->isFriend(friendToRemove);
	if (i < 0)
		return;
	swap(_memberFriends[i], _memberFriends[_numOfFriends-1], sizeof(Member**));
	_memberFriends[_numOfFriends-1] = nullptr;
	_numOfFriends--;
	friendToRemove->removeFriend(this);
	return;
}
int Member::isFan(FanPage* fanPage)
{
	for (int i = 0; i < _numOfFanPages; i++)
		if (_memberFanPages[i] == fanPage)
			return i;
	return NOT_FOUND;
}

void Member::addPage(FanPage* fanPageToAdd)
{
	if (this->isFan(fanPageToAdd) >= 0)
		return;
	if (_numOfFanPages == fanPagesPhySize)
	{
		fanPagesPhySize *= 2;
		_memberFanPages = (FanPage**)myrealloc(_memberFanPages, _numOfFanPages, fanPagesPhySize, sizeof(FanPage*));
	}
	_memberFanPages[_numOfFanPages] = fanPageToAdd;
	_numOfFanPages++;
	fanPageToAdd->addFan(this);
}
void Member:: removePage(FanPage* fanPageToRemove)
{
	int i = this->isFan(fanPageToRemove);
	if (i < 0)
		return;
	swap(_memberFanPages[i], _memberFanPages[_numOfFanPages - 1], sizeof(FanPage*));
	_memberFanPages[_numOfFanPages - 1] = nullptr;
	_numOfFanPages--;
	fanPageToRemove->removeFan(this);
}
//void showAllStatus();
//void showLatestFriendsStatus();