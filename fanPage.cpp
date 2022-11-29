#define _CRT_SECURE_NO_WARNINGS
#include "fanPage.h"
#include "functions.h"

#include <string.h>
FanPage:: FanPage(char* pageName)
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

int FanPage:: isFan(Member* member)
{
	for (int i = 0; i < _numOfFans; i++)
		if (_pageFans[i] == member)
			return i;
	return NOT_FOUND;
}

void FanPage::addFan(Member* fanToAdd)
{
	if (this->isFan(fanToAdd) >= 0)
		return;
	if (_numOfFans == _fansPhySize)
	{
		_fansPhySize *= 2;
		_pageFans = (Member**)myrealloc(_pageFans, _numOfFans, _fansPhySize, sizeof(Member*));
	}
	_pageFans[_numOfFans] = fanToAdd;
	_numOfFans++;
	fanToAdd->addPage(this);
}

void FanPage::removeFan(Member* fan)
{
	int i = this->isFan(fan);
	if (i < 0)
		return;
	swap(_pageFans[i], _pageFans[_numOfFans - 1], sizeof(Member*));
	_pageFans[_numOfFans - 1] = nullptr;
	_numOfFans--;
	fan->removePage(this);
}
