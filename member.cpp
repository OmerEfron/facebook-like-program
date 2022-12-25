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
	_numOfStatus = _numOfFriends = _numOfFanPages = 0;
	_statusesPhySize = _friendsPhySize = fanPagesPhySize = 1;
	_memberStatuses = new Status *[1];
	_memberFriends = new Member * [1];
	_memberFanPages = new FanPage * [1];
}


Member:: ~Member()
{
	delete[] _memberName;
	delete[] _memberStatuses;
	delete[] _memberFriends;
	delete[] _memberFanPages;
}

// gets a ref to a status and adds its address to the member statuses arr.
void Member::addStatus(Status& status)
{
	if (_numOfStatus == _statusesPhySize)
	{
		_statusesPhySize *= 2;
		_memberStatuses = (Status**)reallocArr(_memberStatuses, _numOfStatus, _statusesPhySize, sizeof(Status*));
	}
	Status* statusToAdd = new Status(status.getContent(), status.getDate(), status.getTime());
	_memberStatuses[_numOfStatus] = statusToAdd;
	_numOfStatus++;
}

void Member:: operator+=(Member& memberToAdd)
{
	addFriend(&memberToAdd);
}

bool Member:: operator>(const Member& other) const
{
	return this->_numOfFriends > other._numOfFriends;
}

// checks if member is friend with this member.
// returns the index of the friend in his friends arr if found, NOT_FOUND if not.
int Member::isFriend(Member* member)
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

// add friendToAdd address to this members friends arr.
void Member::addFriend(Member* friendToAdd)
{
	if (this->isFriend(friendToAdd) >= 0)
		return;
	if (_numOfFriends == _friendsPhySize)
	{
		_friendsPhySize *= 2;
		_memberFriends = (Member**)reallocArr(_memberFriends, _numOfFriends, _friendsPhySize, sizeof(Member*));
	}
	_memberFriends[_numOfFriends] = friendToAdd;
	_memberFriends2.push_back(friendToAdd);
	_numOfFriends++;
	friendToAdd->addFriend(this);
}



// removes the friendToRemove address from this member friends arr.
void  Member:: removeFriend(Member* friendToRemove)
{
	int i = this->isFriend(friendToRemove);
	if (i < 0)
		return;
	swap1(&_memberFriends[i], &_memberFriends[_numOfFriends-1], sizeof(Member*));
	_memberFriends[_numOfFriends-1] = nullptr;
	_numOfFriends--;
	vector<Member*>::iterator itr = _memberFriends2.begin();
	vector<Member*>::iterator itrEnd = _memberFriends2.end();
	vector<Member*>::iterator tmp = find(itr, itrEnd, friendToRemove);
	_memberFriends2.erase(tmp);
	friendToRemove->removeFriend(this);
	return;
}

// checks if this member is a fan of the fanPage
int Member::isFan(FanPage* fanPage)
{
	for (int i = 0; i < _numOfFanPages; i++)
		if (_memberFanPages[i] == fanPage)
			return i;
	return NOT_FOUND;
}

// add the fanPageToAdd address to this member pages arr.
void Member::addPage(FanPage* fanPageToAdd)
{
	if (this->isFan(fanPageToAdd) >= 0)
		return;
	if (_numOfFanPages == fanPagesPhySize)
	{
		fanPagesPhySize *= 2;
		_memberFanPages = (FanPage**)reallocArr(_memberFanPages, _numOfFanPages, fanPagesPhySize, sizeof(FanPage*));
	}
	_memberFanPages[_numOfFanPages] = fanPageToAdd;
	_memberFanPages2.push_back(fanPageToAdd);
	_numOfFanPages++;
	fanPageToAdd->addFan(this);
}

// removes fanPageToRemove from this member pages arr.
void Member:: removePage(FanPage* fanPageToRemove)
{
	int i = this->isFan(fanPageToRemove);
	if (i < 0)
		return;
	swap1(&_memberFanPages[i], &_memberFanPages[_numOfFanPages - 1], sizeof(FanPage*));
	_memberFanPages[_numOfFanPages - 1] = nullptr;
	_numOfFanPages--;
	vector<FanPage*>::iterator itr = _memberFanPages2.begin();
	vector<FanPage*>::iterator itrEnd = _memberFanPages2.end();
	vector<FanPage*>::iterator tmp = find(itr, itrEnd, fanPageToRemove);
	_memberFanPages2.erase(tmp);
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

Date Member:: getMemberBirthDate() const
{
	return _dateOfBirth;
}

void Member::showAllFriends(bool withIndex)
{
	if (withIndex) {
	for (int i = 0; i < _numOfFriends; i++)
		cout <<i+1<<". "<< _memberFriends[i]->getMemberName() << "\n";
	}
	else {
		for (int i = 0; i < _numOfFriends; i++)
			cout << _memberFriends[i]->getMemberName() << "\n";
	}
}

void Member::showAllFanpages(bool withIndex)
{
	if (withIndex){
		for (int i = 0; i < _numOfFanPages; i++)
			cout << i+1 << ". " << _memberFanPages[i]->getPageName() << "\n";
	}
	else{
		for (int i = 0; i < _numOfFanPages; i++)
			cout << _memberFanPages[i]->getPageName() << "\n";
	}
}

const Status** Member::getStatuses()  const
{
	return (const Status**)_memberStatuses;
}

// shows the last max 10 statuses of this member's friends.
void Member::showLatestFriendsStatus()
{
	cout << _memberName << " friends latest statuses: \n\n";
	for (int i = 0; i < _numOfFriends; i++)
	{
		int numOfStatuses = _memberFriends[i]->getNumOfStatuses();
		if (numOfStatuses == 0)
			continue;
		cout << _memberFriends[i]->getName() << ":\n\n";
		for (int j = numOfStatuses - 1; j > numOfStatuses - 10 && j >= 0; j--)
		{
			_memberFriends[i]->getStatuses()[j]->showStatus();
			cout << "\n---------------\n";
		}
	}
}

const char* Member:: getName() const
{
	return _memberName;
}

int Member::getNumOfFriends()
{
	return _numOfFriends;
}

Member** const Member::getAllMembers()
{
	return _memberFriends;
}