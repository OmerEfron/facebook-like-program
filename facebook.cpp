#include "facebook.h"
#include "functions.h"
#include <iostream>
using namespace std;

Facebook::Facebook()
{
}

Facebook::~Facebook()
{
	vector<FanPage*>::const_iterator itr1 = _fanPages2.begin();
	vector<FanPage*>::const_iterator itrEnd1 = _fanPages2.end();
	vector<Member*>::const_iterator itr2 = _members2.begin();
	vector<Member*>::const_iterator itrEnd2 = _members2.end();

	for (; itr1 != itrEnd1; ++itr1)
	{
		delete *itr1;
	}
	for (; itr2 != itrEnd2; ++itr2)
	{
		delete *itr2;
	}
}

int Facebook::getNumOfMembers() const
{
	return _members2.size();
}

int Facebook::getNumOfPages() const
{
	return _fanPages2.size();
}

// gets a ref to Member and adds it to facebook
bool Facebook::addMember(Member& newMember)
{
	if (!isNameMemberUsed(newMember))
	{
		 Member* memberToAdd = new Member(newMember.getName(), newMember.getMemberBirthDate());
		_members2.push_back(memberToAdd);
		return true;
	}
	return false;
}

// gets a ref to FanPage and adds it to facebook
bool Facebook::addPage(FanPage& newPage)
{
	if (!isNameFanPageUsed(newPage))
	{
		FanPage* fanPageToAdd = new FanPage(newPage.getPageName());
		_fanPages2.push_back(fanPageToAdd);
		return true;
	}
	return false;
}

// shows all members in facebook.
void Facebook::showMembers() const
{
	cout << "Members: \n";

	vector<Member*>::const_iterator itr = _members2.begin();
	vector<Member*>::const_iterator itrEnd = _members2.end();
	if (itr == itrEnd)
	{
		cout << "No Members"<< endl;
	}
	else
	{
		for (; itr != itrEnd; ++itr)
			cout << (*itr)->getMemberName() << endl;
	}
}

// shows all pages in facebook
void Facebook::showPages() const
{
	cout << "Pages: \n";
	vector<FanPage*>::const_iterator itr = _fanPages2.begin();
	vector<FanPage*>::const_iterator itrEnd = _fanPages2.end();
	if (itr == itrEnd)
	{
		cout << "No Pages" << endl;
	}
	else
	{
		for (; itr != itrEnd; ++itr)
			cout << (*itr)->getPageName() << endl;
	}

}

// returns a const members arr
vector<Member*> const Facebook::getAllMembers()
{
	return _members2;
}
// return a const pages arr
const vector<FanPage*> Facebook::getAllFanPages()
{
	return _fanPages2;
}

bool Facebook::isNameMemberUsed(Member& member)
{
	vector<Member*>::const_iterator itr = _members2.begin();
	vector<Member*>::const_iterator itrEnd = _members2.end();

	for (; itr != itrEnd; ++itr)
	{
		if (strcmp(member.getName(), (*itr)->getName()) == 0)
			return true;
	}
	return false;
}

bool Facebook::isNameFanPageUsed(FanPage& fanPage)
{
	vector<FanPage*>::const_iterator itr = _fanPages2.begin();
	vector<FanPage*>::const_iterator itrEnd = _fanPages2.end();

	for (; itr != itrEnd; ++itr)
	{
		if (strcmp(fanPage.getPageName(), (*itr)->getPageName()) == 0)
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

FanPage* Facebook::findFanPage(int index)
{
	vector<FanPage*>::iterator itr = _fanPages2.begin();
	return (*itr) + index;
}

Member* Facebook::findMember(int index)
{
	vector<Member*>::iterator itr = _members2.begin();
	return (*itr) + index;
}