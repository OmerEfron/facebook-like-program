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
	bool isEmptyList();
	void insertNodeToEndList(listNodeOfStatus* newHead);
	void insertDataToEndList(Status* status);
	void addNewStatus(Status* status);
};