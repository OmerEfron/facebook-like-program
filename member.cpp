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
}

int Member::isFriend(Member* member) // returns the index of the friend if found, NOT_FOUND if not.
{
	for (int i = 0; i < _numOfFriends; i++)
		if (member == _memberFriends[i])
			return i;
	return NOT_FOUND;
}

int Member:: getNumOfStatuses()
{
	return _numOfStatus;
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
void Member::showAllStatus() const
{
	for (int i = 0; i < _numOfStatus; i++)
	{
		_memberStatuses[i]->showStatus();
		cout << "\n---------------------\n";
	}
}

const char* Member:: getMemberName()
{
	return _memberName;
}

void Member::showAllFriends()
{
	for (int i = 0; i < _numOfFriends; i++)
	{
		cout << _memberFriends[i]->getMemberName()<<"\n";
	}
}

void Member::showAllFanpages()
{
	for (int i = 0; i < _numOfFanPages; i++)
	{
		cout << _memberFanPages[i]->getPageName()<<"\n";
	}
}

const Status** Member::getStatuses()  const
{
	return (const Status**)_memberStatuses;
}

void Member::showLatestFriendsStatus()
{
	
	for (int i = 0; i < _numOfFriends; i++)
	{
		int numOfStatuses = _memberFriends[i]->getNumOfStatuses();
		if (numOfStatuses == 0)
			continue;
		for (int j = numOfStatuses - 1; j > numOfStatuses - 10 && j >= 0; j--)
		{
			_memberFriends[i]->getStatuses()[j]->showStatus();
			cout << "\n__________________\n";
		}
	}
}

const char* Member:: getName() const
{
	return _memberName;
}
