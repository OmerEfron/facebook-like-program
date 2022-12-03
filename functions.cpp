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


// reallocate the arr, from any type, with a size of the given phySize.
//copies the first logSize elements to the new arr and free the old one.
void* reallocArr(void* arr, int logSize, int physize, int elemSize)
{
	void* newArr;
	newArr = new unsigned char[elemSize * physize];
	memcpy(newArr, (unsigned char*)arr, logSize * elemSize);
	delete arr;
	return newArr;
}

// swap adresses between 2 elements from same type.
void swap1(void* x, void* y, int elemSize)
{
	void* temp = malloc(elemSize);
	memcpy((unsigned char*)temp, (unsigned char*)y, elemSize);
	memcpy((unsigned char*)y, (unsigned char*)x, elemSize);
	memcpy((unsigned char*)x, (unsigned char*)temp, elemSize);
	free(temp);
}

// display the system menu.
void displayMenu()
{
	cout << "Welcome to FACEBOOK\n----------------------\nPlease choose one of the following:\n"
		<< "1 - Add new member.\n2 - Add new fan page.\n3 - Add status to member.\n"
		<<"4 - Add status to fan page.\n5 - Show a member statuses.\n6 - Show a fan page statuses\n"
		<<"7 - Show a member latest 10 statuses.\n8 - Create new friendship between two members.\n"
		<<"9 - Cancel a friendship between 2 friends\n10 - Add a members as a fan to a fan page.\n"
		<<"11 - Remove a member from a fan page.\n12 - Show all members in facebook.\n"
		<<"13 - Show a member friends.\n" "14 - Show a fan page fans.\n15 - Exit\n";
}

// get the user choice number, and based on it executing his choice.
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

// adds a new member to facebook. 
// gets from user the name and birthdate.
// if there is already a member in facebook with same name, free the name and the new member.
void addNewMember(Facebook& facebook)
{
	int day, month, year;
	char* name;
	cout << "Please enter the new member's name:\n";
	name = getString();
	cout << "Please enter:\nDay Month Year, seperated with white space\n";
	cin >> day >> month >> year;
	Member* member = new Member(name, Date(day, month, year));
	if (!facebook.addMember(*member))
		delete member;

}

// adds a new page to facebook. 
// gets from user the name and birthdate.
// if there is already a page in facebook with same name, free the name and the new page.
void addNewFanPage(Facebook& facebook)
{
	char* name;
	cout << "Please enter the new page's name:\n";
	name = getString();

	FanPage* fanPage = new FanPage(name);
	if (!facebook.addPage(*fanPage))
		delete fanPage;
}

// adds a new status to page. 
// gets from user the page to add the status to, the date and the content.
void addStatusToPage(Facebook& facebook)
{
	int choice = checkInputFanPages(facebook);
	int day, month, year, hour, minutes;
	
	char* content;
	cout << "Enter: Day, Month, Year, Hour, Minutes\n";
	cin >> day >> month >> year >> hour >> minutes;
	cout << "\nEnter content: \n";
	getchar();
	content = getString();
	Status* newStatus = new Status(content, Date(day, month, year), Time(hour, minutes));
	facebook.getAllFanPages()[choice-1]->addStatus(*newStatus);
}

// adds a new status to member. 
// gets from user the member to add the status to, the date and the content.
void addStatusToMember(Facebook& facebook)
{
	int choice = checkInputMembers(facebook);
	int day, month, year, hour, minutes;
	
	char* content;
	cout << "Enter: Day, Month, Year, Hour, Minutes\n";
	cin >> day >> month >> year >> hour >> minutes;
	cout << "\nEnter content: \n";
	getchar();
	content = getString();
	Status* newStatus = new Status(content, Date(day, month, year), Time(hour, minutes));
	facebook.getAllMembers()[choice-1]->addStatus(*newStatus);
}

// print the fan pages with fixed indexes
void printFanPagesChoices(Facebook& facebook)
{
	for (int i = 0; i < facebook.getNumOfPages(); i++)
	{
		cout << i + 1 << " - " << facebook.getAllFanPages()[i]->getPageName() << "\n";
	}
}
// print the members with fixed indexes
void printFriendsChoices(Facebook& facebook)
{
	for (int i = 0; i < facebook.getNumOfMembers(); i++)
	{
		cout << i + 1 << " - " << facebook.getAllMembers()[i]->getName() << "\n";
	}
}

// gets from user a string.
// returns a dynamic string 
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
			name = (char*)reallocArr(name, logSize, phySize, sizeof(char));
		}
		name[logSize] = ch;
		logSize++;
		ch = getchar();
	}
	name[logSize] = '\0';
	return name;
}

// gets from user a page choice and shows all of his statuses.
void showAllStastusOfPage(Facebook& facebook)
{
	int choice = checkInputFanPages(facebook);
	facebook.getAllFanPages()[choice-1]->showAllStatus();
}

// gets from user a member choice and shows all of his statuses.
void showAllStatusOfMember(Facebook& facebook)
{
	int choice = checkInputMembers(facebook);
	facebook.getAllMembers()[choice - 1]->showAllStatus();
}

// gets from user a member choice and shows all of his friends 10 latest statuses.
void showLatestStatusOfFriend(Facebook& facebook)
{
	int choice= checkInputMembers(facebook);
	facebook.getAllMembers()[choice - 1]->showLatestFriendsStatus();
}
// gets from user two members and connect both of them as friends on facebook
void makeFriends(Facebook& facebook)
{
	int choice1, choice2;
	int numOfMembers = facebook.getNumOfMembers();
	do{
		cout << "Please choose two members:\n";
		printFriendsChoices(facebook);
		cin >> choice1>> choice2;
	} while (choice2 == choice1 || choice2<1 || choice2>numOfMembers || choice1<1 || choice1>numOfMembers);

	Member* temp1 = facebook.getAllMembers()[choice1 - 1];
	Member* temp2 = facebook.getAllMembers()[choice2 - 1];
	temp1->addFriend(temp2);
}
// gets from user two members and remove them from being friends on facebook.
void cancelFriendship(Facebook& facebook)
{
	int choice1 = checkInputMembers(facebook);
	int choice2;
	int numOfMembers = facebook.getAllMembers()[choice1 - 1]->getNumOfMembers();

	if (numOfMembers > 0)
	{
		do {
			cout << "Please choose the second member:\n";
			facebook.getAllMembers()[choice1 - 1]->showAllFriends(true);
			cin >> choice2;
			getchar();
		} while (choice2<1 || choice2>numOfMembers);

		Member* temp1 = facebook.getAllMembers()[choice1 - 1];
		Member* temp2 = facebook.getAllMembers()[choice1 - 1]->getAllMembers()[choice2 - 1];
		temp1->removeFriend(temp2);
	}
	else
		cout << "No have members";
}
// gets from the user a member and a page choice.
// adds the member to be a fan of the fan page.
void addMemberToPage(Facebook& facebook)
{
	int page = checkInputFanPages(facebook);
	int member = checkInputMembers(facebook);
	
	facebook.getAllFanPages()[page - 1]->addFan(facebook.getAllMembers()[member - 1]);
}

// gets a member and a fan page and removes the member from being a fan of the page.
void removeMemberFromPage(Facebook& facebook)
{
	int page, member;
	page = checkInputFanPages(facebook);

	int numOfMembers = facebook.getAllFanPages()[page - 1]->getNumOfFans();
	if (numOfMembers > 0)
	{
		do {
			cout << "Please choose one fan:\n";
			facebook.getAllFanPages()[page - 1]->showAllFans(true);
			cin >> member;
			getchar();
		} while (member<1 || member>numOfMembers);
		facebook.getAllFanPages()[page - 1]->removeFan(facebook.getAllFanPages()[page - 1]->getPageFans()[member - 1]);
	}
	else
		cout << "No have fans";
}

// shows all members and pages on facebook.
void showAll(Facebook& facebook)
{
	cout << "All the members on facebook:\n";
	facebook.showMembers();
	cout << "\n----------------\n";
	cout << "All the fan pages on facebook:\n";
	facebook.showPages();
}

// gets a member and shows all of his friends
void showMemberFriends(Facebook& facebook)
{
	int choice = checkInputMembers(facebook);

	facebook.getAllMembers()[choice - 1]->showAllFriends(false);
}

// gets a page and shows all of his fans
void showPageFans(Facebook& facebook)
{
	int choice = checkInputFanPages(facebook);

	facebook.getAllFanPages()[choice - 1]->showAllFans(false);
}

int checkInputMembers(Facebook& facebook)
{
	int choice;
	int numOfMembers = facebook.getNumOfMembers();
	do {
		cout << "Please choose the first member:\n";
		printFriendsChoices(facebook);
		cin >> choice;
		getchar();
	} while (choice<1 || choice>numOfMembers);
	return choice;
}
int checkInputFanPages(Facebook& facebook)
{
	int choice;
	int numOfPages = facebook.getNumOfPages();
	do {
		cout << "Please choose one fan page:\n";
		printFanPagesChoices(facebook);
		cin >> choice;
		getchar();
	} while (choice<1 || choice>numOfPages);
	return choice;
}