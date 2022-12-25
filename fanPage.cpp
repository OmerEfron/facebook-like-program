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
	_numOfStatus = 0;
	_numOfFans = 0;
	_statusesPhySize = 1;
	_fansPhySize = 1;
	_pageStatuses = new Status*[_statusesPhySize];
	_pageFans = new Member * [_fansPhySize];
}

FanPage:: ~FanPage()
{
	delete[] _pageName;
	delete[] _pageStatuses;
	delete[] _pageFans;
}

// checks if a member is a fan of the page
vector<Member*>::iterator FanPage:: isFan(Member* member)
{
	/*for (int i = 0; i < _numOfFans; i++)
		if (_pageFans[i] == member)
			return i;*/
	vector<Member*>::iterator itr = _pageFans2.begin();
	vector<Member*>::iterator itrEnd = _pageFans2.end();
	vector<Member*>::iterator tmp = find(itr, itrEnd, member);

	return tmp;
}

// adds a new status to the page
void FanPage:: addStatus(Status& status)
{
	if (_numOfStatus == _statusesPhySize)
	{
		_statusesPhySize *= 2;
		_pageStatuses = (Status**)reallocArr(_pageStatuses, _numOfStatus, _statusesPhySize, sizeof(Status*));
	}
	Status* newStatus = new Status(status.getContent(), status.getDate(), status.getTime());
	_pageStatuses[_numOfStatus] = newStatus;
	_numOfStatus++;
}

// adds a new fan to the page.
void FanPage::addFan(Member* fanToAdd)
{
	if (this->isFan(fanToAdd) != _pageFans2.end())
		return;
	if (_numOfFans == _fansPhySize)
	{
		_fansPhySize *= 2;
		_pageFans = (Member**)reallocArr(_pageFans, _numOfFans, _fansPhySize, sizeof(Member*));
	}
	_pageFans[_numOfFans] = fanToAdd;
	_pageFans2.push_back(fanToAdd);
	_numOfFans++;
	fanToAdd->addPage(this);
}

// removes a member from being a fan of the page
void FanPage::removeFan(Member* fan)
{
	if (this->isFan(fan) == _pageFans2.end())
		return;
	/*swap1(&_pageFans[i], &_pageFans[_numOfFans - 1],sizeof(Member*));
	_pageFans[_numOfFans - 1] = nullptr;
	_numOfFans--;*/
	vector<Member*>::iterator itr = _pageFans2.begin();
	vector<Member*>::iterator itrEnd = _pageFans2.end();
	vector<Member*>::iterator tmp = find(itr, itrEnd, fan);
	_pageFans2.erase(tmp);
	fan->removePage(this);
}

// shows all of the fans of the page.
void FanPage::showAllFans(bool withIndex)
{
	cout << _pageName << " Fans: \n";
	vector<Member*>::const_iterator itr = _pageFans2.begin();
	vector<Member*>::const_iterator itrEnd = _pageFans2.end();
	if (itr == itrEnd)
	{
		cout << "No Pages" << endl;
	}
	else
	{
		if (withIndex)
		{
			for (int i = 1; itr != itrEnd; ++itr, ++i)
				cout << i << ". " << ((Member*)*itr)->getMemberName() << endl;
		}
		else
		{
			for (; itr != itrEnd; ++itr)
				cout << ((Member*)*itr)->getMemberName() << endl;
		}
	}
	/*cout << _pageName << " fans: \n";
	if (withIndex)
	{
		for (int i = 0; i < _numOfFans; i++)
			cout <<i+1<<". "<< _pageFans[i]->getMemberName() << "\n";

	}
	else {
		for (int i = 0; i < _numOfFans; i++)
			cout << _pageFans[i]->getMemberName() << "\n";
		
	}*/
}

// shows all of the statuses of the page.
void FanPage::showAllStatus()
{
	for (int i = 0; i < _numOfStatus; i++)
	{
		_pageStatuses[i]->showStatus();
		cout << "\n";
	}
}

const char* FanPage:: getPageName()
{
	return _pageName;
}

int FanPage:: getNumOfFans()
{
	return _numOfFans;
}

vector<Member*> const FanPage::getPageFans()
{
	return _pageFans2;
}

bool FanPage:: operator>(const FanPage& other)const
{
	return this->_numOfFans > other._numOfFans;
}