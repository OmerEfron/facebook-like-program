#ifndef LIST_OF_STATUSES_H
#define LIST_OF_STATUSES_H

#include "status.h"

class listNodeOfStatus {
private:
	Status* data;
	listNodeOfStatus* next;
public:
	listNodeOfStatus(Status* data);
};

class listOfStatuses {
private:
	int listSize;
	listNodeOfStatus* head;
	listNodeOfStatus* tail;
public:
	listOfStatuses();
	~listOfStatuses();
	bool isEmptyList();
	void removeNodeFromEndList(listNodeOfStatus* newHead);
	void removeDataFromEndList(Status* status);
	void insertNodeToStartList(listNodeOfStatus* newHead);
	void insertDataToStartList(Status* status);
	void addNewStatus(Status* status);
};

#endif // !LIST_OF_STATUSES_H