#define _CRT_SECURE_NO_WARNINGS
#include "fanPage.h"
#include "functions.h"
#include <iostream>
#include <string.h>
using namespace std;


FanPage:: FanPage(const char* pageName)
{
	_pageName = new char[strlen(pageName)+1];
	strcpy(_pageName, pageName);

}

FanPage:: ~FanPage()
{
	vector<Status*>::iterator itr = _pageStatus2.begin();
	vector<Status*>::iterator itrEnd = _pageStatus2.end();
	for (; itr != itrEnd; ++itr)
	{
		delete* itr;
	}
	delete[] _pageName;
}

// adds a new status to the page
void FanPage:: addStatus(Status& status)
{
	Status* newStatus = new Status(status.getContent(), status.getDate(), status.getTime());
	_pageStatus2.push_back(newStatus);
}

// adds a new fan to the page.
void FanPage::addFan(Member* fanToAdd)
{
	vector<Member*>::iterator itr = _pageFans2.begin();
	vector<Member*>::iterator itrEnd = _pageFans2.end();
	vector<Member*>::iterator tmp = find(itr, itrEnd, fanToAdd);
	if (tmp != itrEnd)
		return;

	_pageFans2.push_back(fanToAdd);
	fanToAdd->addPage(this);
}

// removes a member from being a fan of the page
void FanPage::removeFan(Member* fan)
{
	vector<Member*>::iterator itr = _pageFans2.begin();
	vector<Member*>::iterator itrEnd = _pageFans2.end();
	vector<Member*>::iterator tmp = find(itr, itrEnd, fan);
	if (tmp == itrEnd)
		return;
	_pageFans2.erase(tmp);
	fan->removePage(this);
}

// shows all of the fans of the page.
void FanPage::showAllFans(bool withIndex)
{
	cout << _pageName << " Fans: \n";
	vector<Member*>::const_iterator itr = _pageFans2.begin();
	vector<Member*>::const_iterator itrEnd = _pageFans2.end();
	if (itr == itrEnd){
		cout << "No Pages" << endl;
	}
	else{
		if (withIndex)
		{
			for (int i = 1; itr != itrEnd; ++itr, ++i)
				cout << i << ". " << (*itr)->getMemberName() << endl;
		}
		else
		{
			for (; itr != itrEnd; ++itr)
				cout << (*itr)->getMemberName() << endl;
		}
	}
}

// shows all of the statuses of the page.
void FanPage::showAllStatus()
{
	vector<Status*>::const_iterator itr = _pageStatus2.begin();
	vector<Status*>::const_iterator itrEnd = _pageStatus2.end();
	for (; itr != itrEnd; ++itr)
	{
		(*itr)->showStatus();
		cout << "\n---------------------\n";
	}

}

const char* FanPage:: getPageName()
{
	return _pageName;
}

int FanPage:: getNumOfFans() const
{
	return _pageFans2.size();
}

vector<Member*> const FanPage::getPageFans()
{
	return _pageFans2;
}

bool FanPage:: operator>(const FanPage& other)const
{
	return getNumOfFans() > other.getNumOfFans();
}