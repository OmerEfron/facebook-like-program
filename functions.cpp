#include "functions.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>
#define ADD_NEW_MEMBER 1
#define ADD_NEW_FAN_PAGE 2
#define ADD_NEW_STATUS_TO_MEMBER 3
#define ADD_NEW_STATUS_TO_FAN_PAGE 4
#define SHOW_ALL_STATUS_OF_MEMBER 5
#define SHOW_ALL_STATUS_OF_FAN_PAGE 6
#define SHOW_MEMBER_LATEST_FRIENDS_STATUSES 7
#define CREATE_NEW_FRIENDSHIP 8
#define CANCEL_FRIENDSHIP 9
#define ADD_FAN_TO_FAN_PAGE 10
#define REMOVE_FAN_TO_FAN_PAGE 11
#define SHOW_ALL 12
#define SHOW_ALL_MEMBER_FRIENDS 13
#define SHOW_ALL_FANS_OF_FAN_PAGE 14
#define EXIT 15
using namespace std;

void* myrealloc(void* arr, int& logSize, int& physize, int elemSize)
{
	void* newArr;
	newArr = new unsigned char[elemSize * physize];
	memcpy(newArr, (unsigned char*)arr, logSize * elemSize);
	delete arr;
	return newArr;
}

void swap1(void* x, void* y, int elemSize)
{
	void* temp = malloc(elemSize);
	memcpy((unsigned char*)temp, (unsigned char*)y, elemSize);
	memcpy((unsigned char*)y, (unsigned char*)x, elemSize);
	memcpy((unsigned char*)x, (unsigned char*)temp, elemSize);
	free(temp);
}

void displayMenu()
{
	cout << "Welcome to FACEBOOK\n-------------\nPlease choose one of the following:\n"
		<< "1 - Add new member.\n2 - Add new fan page.\n3 - Add status to member.\n"
		<<"4 - Add status to fan page.\n5 - Show a member statuses.\n6 - Show a fan page statuses\n"
		<<"7 - Show a member latest 10 statuses.\n8 - Create new friendship between two members.\n"
		<<"9 - Cancel a friendship between 2 friends\n10 - Add a members as a fan to a fan page.\n"
		<<"11 - Remove a member from a fan page.\n12 - Show all members in facebook.\n"
		<<"13 - Show a member friends.\n" "14 - Show a fan page fans.\n15 - Exit\n";
}

bool getChoice(Facebook& facebook)
{
	int choice;
	displayMenu();
	do {
		cin >> choice;
	} while (choice < 1 || choice > 15);
	getchar();
	switch (choice)
	{
	case ADD_NEW_MEMBER:
	{
		addNewMember(facebook);
		break;
	}
	case ADD_NEW_FAN_PAGE:
	{
		addNewFanPage(facebook);
		break;
	}
	case ADD_NEW_STATUS_TO_MEMBER:
	{
		if(facebook.getNumOfMembers() != 0)
			addStatusToMember(facebook);
		break;
	}
	case ADD_NEW_STATUS_TO_FAN_PAGE:
	{
		if (facebook.getNumOfMembers() != 0)
			addStatusToPage(facebook);
		break;
	}
	case SHOW_ALL_STATUS_OF_MEMBER:
	{
		showAllStatusOfMember(facebook);
		break;
	}
	case SHOW_ALL_STATUS_OF_FAN_PAGE:
	{
		showAllStastusOfPage(facebook);
		break;
	}
	case SHOW_MEMBER_LATEST_FRIENDS_STATUSES:
	{
		showLatestStatusOfFriend(facebook);
		break;
	}
	case CREATE_NEW_FRIENDSHIP:
	{
		makeFriends(facebook);
		break;
	}
	case CANCEL_FRIENDSHIP:
	{
		cancelFriendship(facebook);
		break;
	}
	case ADD_FAN_TO_FAN_PAGE:
	{
		addMemberToPage(facebook);
		break;
	}
	case REMOVE_FAN_TO_FAN_PAGE:
	{
		removeMemberFromPage(facebook);
		break;
	}
	case SHOW_ALL:
	{
		showAll(facebook);
		break;
	}
	case SHOW_ALL_MEMBER_FRIENDS:
	{
		showMemberFriends(facebook);
		break;
	}
	case SHOW_ALL_FANS_OF_FAN_PAGE :
	{
		showPageFans(facebook);
		break;
	}
	case EXIT:
		return false;
	}
	return true;
}

void addNewMember(Facebook& facebook)
{
	int day, month, year;
	char* name;
	cout << "Please enter the new member's name:\n";
	name = getString();
	cout << "Please enter:\nDay Month Year, seperated with white space\n";
	cin >> day >> month >> year;
	Member* member = new Member(name, Date(day, month, year));
	facebook.addMember(*member);
}

void addNewFanPage(Facebook& facebook)
{
	char* name;
	cout << "Please enter the new page's name:\n";
	name = getString();

	FanPage* fanPage = new FanPage(name);
	facebook.addPage(*fanPage);
}

void addStatusToPage(Facebook& facebook)
{
	int choice, day, month, year, hour, minutes;
	printFanPagesChoices(facebook);
	cin >> choice;
	choice--;
	char* content;
	cout << "Enter: Day, Month, Year, Hour, Minutes\n";
	cin >> day >> month >> year >> hour >> minutes;
	cout << "\nEnter content: \n";
	getchar();
	content = getString();
	Status* newStatus = new Status(content, Date(day, month, year), Time(hour, minutes));
	facebook.getAllFanPages()[choice]->addStatus(*newStatus);
}

void addStatusToMember(Facebook& facebook)
{
	int choice, day, month, year, hour, minutes;
	printFriendsChoices(facebook);
	cin >> choice;
	char* content;
	cout << "Enter: Day, Month, Year, Hour, Minutes\n";
	cin >> day >> month >> year >> hour >> minutes;
	cout << "\nEnter content: \n";
	getchar();
	content = getString();
	Status* newStatus = new Status(content, Date(day, month, year), Time(hour, minutes));
	facebook.getAllMembers()[choice-1]->addStatus(*newStatus);
}

void printFanPagesChoices(Facebook& facebook)
{
	cout << "Please choose a page:\n";
	for (int i = 0; i < facebook.getNumOfPages(); i++)
	{
		cout << i + 1 << " - " << facebook.getAllFanPages()[i]->getPageName() << "\n";
	}
}

void printFriendsChoices(Facebook& facebook)
{
	cout << "Please choose a member: \n";
	for (int i = 0; i < facebook.getNumOfMembers(); i++)
	{
		cout << i + 1 << " - " << facebook.getAllMembers()[i]->getName() << "\n";
	}
}

char* getString()
{
	int logSize = 0, phySize = 1;
	char* name = new char[phySize];
	char ch;
	ch = getchar();
	while (ch != '\n')
	{
		if (phySize == logSize)
		{
			phySize *= 2;
			name = (char*)myrealloc(name, logSize, phySize, sizeof(char));
		}
		name[logSize] = ch;
		logSize++;
		ch = getchar();
	}
	name[logSize] = '\0';
	return name;
}

void showAllStastusOfPage(Facebook& facebook)
{
	int choice;
	printFanPagesChoices(facebook);
	cin >> choice;
	facebook.getAllFanPages()[choice]->showAllStatus();
}

void showAllStatusOfMember(Facebook& facebook)
{
	int choice;
	printFriendsChoices(facebook);
	cin >> choice;
	facebook.getAllMembers()[choice - 1]->showAllStatus();
}
void showLatestStatusOfFriend(Facebook& facebook)
{
	int choice;
	printFriendsChoices(facebook);
	cin >> choice;
	facebook.getAllMembers()[choice - 1]->showLatestFriendsStatus();
}
void makeFriends(Facebook& facebook)
{
	int choice1, choice2;
	do{
		printFriendsChoices(facebook);
		cin >> choice1>> choice2;
	}
	while (choice2 == choice1);
	Member* temp1 = facebook.getAllMembers()[choice1 - 1];
	Member* temp2 = facebook.getAllMembers()[choice2 - 1];
	temp1->addFriend(temp2);
}
void cancelFriendship(Facebook& facebook)
{
	int choice1, choice2;
	do {
		printFriendsChoices(facebook);
		cin >> choice1 >> choice2;
	} while (choice2 == choice1);
	Member* temp1 = facebook.getAllMembers()[choice1 - 1];
	Member* temp2 = facebook.getAllMembers()[choice2 - 1];
	temp1->removeFriend(temp2);
}

void addMemberToPage(Facebook& facebook)
{
	int page, member;
	printFanPagesChoices(facebook);
	cin >> page;
	getchar();
	printFriendsChoices(facebook);
	cin >> member;
	getchar();
	facebook.getAllFanPages()[page - 1]->addFan(facebook.getAllMembers()[member-1]);
}
void removeMemberFromPage(Facebook& facebook)
{
	int page, member;
	printFanPagesChoices(facebook);
	cin >> page;
	getchar();
	printFriendsChoices(facebook);
	cin >> member;
	facebook.getAllFanPages()[page - 1]->removeFan(facebook.getAllMembers()[member - 1]);
}
void showAll(Facebook& facebook)
{
	facebook.showMembers();
	cout << "\n----------------\n";
	facebook.showPages();
}
void showMemberFriends(Facebook& facebook)
{
	int choice;
	printFriendsChoices(facebook);
	cin >> choice;
	getchar();
	facebook.getAllMembers()[choice - 1]->showAllFriends();
}
void showPageFans(Facebook& facebook)
{

	int choice;
	printFanPagesChoices(facebook);
	cin >> choice;
	getchar();
	facebook.getAllFanPages()[choice - 1]->showAllFans();
}
