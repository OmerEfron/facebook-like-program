#define _CRT_SECURE_NO_WARNINGS
#include "member.h"
#include "functions.h"
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
	for (int i = 0; i < _numOfStatus; i++)
		delete _memberStatuses[i];
	delete _memberStatuses;
	delete _memberFriends;
	delete _memberFanPages;
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

//void Member::addFriend(Member& friendToAdd)
//{
//
//}
//void removeFriend(Member& friendToRemove);
//void addPage(FanPage& fanPageToAdd);
//void removePage(FanPage& fanPageToRemove);
//void showAllStatus();
//void showLatestFriendsStatus();