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
		 Member* memberToAdd = new Member(newMember.getName(), newMember.getMemberBirthDate());
		_members[_numOfMembers] = memberToAdd;
		_members2.push_back(memberToAdd);
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
		FanPage* fanPageToAdd = new FanPage(newPage.getPageName());
		_fanPages[_numOfPages] = fanPageToAdd;
		_fanPages2.push_back(fanPageToAdd);
		_numOfPages++;
		return true;
	}
	return false;
}

// shows all members in facebook.
void Facebook::showMembers() const
{
	cout << "Members: \n";
	//for (int i = 0; i < _numOfMembers; i++)
	//{
	//	cout<<_members[i]->getMemberName()<<"\n";
	//}
	vector<Member*>::const_iterator itr = _members2.begin();
	vector<Member*>::const_iterator itrEnd = _members2.end();
	if (itr == itrEnd)
	{
		cout << "No Members"<< endl;
	}
	else
	{
		for (; itr != itrEnd; ++itr)
			cout << ((Member*)*itr)->getMemberName() << endl;
	}
}

// shows all pages in facebook
void Facebook::showPages() const
{
	cout << "Pages: \n";
	/*for (int i = 0; i < _numOfPages; i++)
	{
		cout << _fanPages[i]->getPageName() << "\n";
	}*/

	vector<FanPage*>::const_iterator itr = _fanPages2.begin();
	vector<FanPage*>::const_iterator itrEnd = _fanPages2.end();
	if (itr == itrEnd)
	{
		cout << "No Pages" << endl;
	}
	else
	{
		for (; itr != itrEnd; ++itr)
			cout << ((FanPage*)*itr)->getPageName() << endl;
	}

}

// returns a const members arr
vector<Member*> const Facebook::getAllMembers()
{
	return _members2;
}
// return a const pages arr
vector<FanPage*> const Facebook::getAllFanPages()
{
	return _fanPages2;
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

void Facebook:: removeMemberFromPage(FanPage& page, Member& member)
{
	page.removeFan(&member);
}

void Facebook::cancelFriendship(Member& mem1, Member& mem2)
{
	mem1.removeFriend(&mem2);
}