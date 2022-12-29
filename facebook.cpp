#include "facebook.h"
#include "functions.h"

#include <iostream>
using namespace std;

Facebook::Facebook()
{
}

Facebook::~Facebook()
{
	vector<FanPage*>::const_iterator itr1 = _fanPages.begin();
	vector<FanPage*>::const_iterator itrEnd1 = _fanPages.end();
	vector<Member*>::const_iterator itr2 = _members.begin();
	vector<Member*>::const_iterator itrEnd2 = _members.end();

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
	return (int)_members.size();
}

int Facebook::getNumOfPages() const
{
	return (int)_fanPages.size();
}

// gets a ref to Member and adds it to facebook
void Facebook::addMember(Member& newMember) noexcept(false)
{
	if (isNameMemberUsed(newMember))
	{
		throw DuplicateNameException(newMember.getMemberName());
	}
	else if (!(newMember.getMemberBirthDate().isValid()))
	{
		throw InvalidBirthDate();
	}
	else
	{
		Member* memberToAdd = new Member(newMember.getMemberName(), newMember.getMemberBirthDate());
		_members.push_back(memberToAdd);
	}
}

// gets a ref to FanPage and adds it to facebook
bool Facebook::addPage(FanPage& newPage)
{
	if (!isNameFanPageUsed(newPage))
	{
		FanPage* fanPageToAdd = new FanPage(newPage.getPageName());
		_fanPages.push_back(fanPageToAdd);
		return true;
	}
	return false;
}

// shows all members in facebook.
void Facebook::showMembers() const
{
	cout << "Members: \n";

	vector<Member*>::const_iterator itr = _members.begin();
	vector<Member*>::const_iterator itrEnd = _members.end();
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
	vector<FanPage*>::const_iterator itr = _fanPages.begin();
	vector<FanPage*>::const_iterator itrEnd = _fanPages.end();
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
	return _members;
}
// return a const pages arr
const vector<FanPage*> Facebook::getAllFanPages()
{
	return _fanPages;
}

bool Facebook::isNameMemberUsed(Member& member)
{
	vector<Member*>::const_iterator itr = _members.begin();
	vector<Member*>::const_iterator itrEnd = _members.end();

	for (; itr != itrEnd; ++itr)
	{
		if (member.getMemberName() == (*itr)->getMemberName())
			return true;
	}
	return false;
}

bool Facebook::isNameFanPageUsed(FanPage& fanPage)
{
	vector<FanPage*>::const_iterator itr = _fanPages.begin();
	vector<FanPage*>::const_iterator itrEnd = _fanPages.end();

	for (; itr != itrEnd; ++itr)
	{
		if (fanPage.getPageName() == (*itr)->getPageName())
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
	vector<FanPage*>::iterator itr = _fanPages.begin() + index;
	return (*itr);
}

Member* Facebook::findMember(int index)
{
	vector<Member*>::iterator itr = _members.begin() + index;
	return (*itr);
}

void Facebook::addMemberToPage(FanPage& page, Member& member)
{
	page.addFan(&member);
}


void Facebook::addStatusToMember(Member& member, Status& status)
{
	member.addStatus(status);
}


void Facebook::makeFriends(Member& member1, Member& member2) noexcept(false)
{
	if (member1.getMemberName() == member2.getMemberName())
		throw AddingMemberToHimself();
	member1.addFriend(&member2);
}