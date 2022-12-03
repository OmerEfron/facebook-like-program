#include "facebook.h"
#include "functions.h"
#include <iostream>
using namespace std;

Facebook::Facebook()
{
	_numOfMembers = _numOfPages = 0;
	_membersPhySize = _pagesPhySize = 1;
	_members = new Member * [_membersPhySize];
	_fanPages = new FanPage * [_pagesPhySize];
}

Facebook::~Facebook()
{
	delete[] _members;
	delete[] _fanPages;
}

int Facebook::getNumOfMembers() const
{
	return _numOfMembers;
}

int Facebook::getNumOfPages() const
{
	return _numOfPages;
}

// gets a ref to Member and adds it to facebook
bool Facebook::addMember(Member& newMember)
{
	if (!isNameMemberUsed(newMember))
	{
		if (_numOfMembers == _membersPhySize)
		{
			_membersPhySize *= 2;
			_members = (Member**)reallocArr(_members, _numOfMembers, _membersPhySize, sizeof(Member*));
		}
		_members[_numOfMembers] = &newMember;
		_numOfMembers++;
		return true;
	}
	return false;
}

// gets a ref to FanPage and adds it to facebook
bool Facebook::addPage(FanPage& newPage)
{
	if (!isNameFanPageUsed(newPage))
	{
		if (_numOfPages == _pagesPhySize)
		{
			_pagesPhySize *= 2;
			_fanPages = (FanPage**)reallocArr(_fanPages, _numOfPages, _pagesPhySize, sizeof(FanPage*));
		}
		_fanPages[_numOfPages] = &newPage;
		_numOfPages++;
		return true;
	}
	return false;
}

// shows all members in facebook.
void Facebook::showMembers() const
{
	cout << "Members: \n";
	for (int i = 0; i < _numOfMembers; i++)
	{
		cout<<_members[i]->getMemberName()<<"\n";
	}
}

// shows all pages in facebook
void Facebook::showPages() const
{
	cout << "Pages: \n";
	for (int i = 0; i < _numOfPages; i++)
	{
		cout << _fanPages[i]->getPageName() << "\n";
	}
}

// returns a const members arr
Member** const Facebook::getAllMembers() 
{
	return _members;
}
// return a const pages arr
FanPage** const Facebook::getAllFanPages()
{
	return _fanPages;
}

bool Facebook::isNameMemberUsed(Member& member)
{
	for (int i = 0; i < _numOfMembers; i++)
	{
		if (strcmp(member.getName(), _members[i]->getName()) == 0)
			return true;
	}
	return false;
}
bool Facebook::isNameFanPageUsed(FanPage& fanPage)
{
	for (int i = 0; i < _numOfPages; i++)
	{
		if (strcmp(fanPage.getPageName(), _fanPages[i]->getPageName()) == 0)
			return true;
	}
	return false;
}