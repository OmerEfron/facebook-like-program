#include "functions.h"
#include <string.h>
void* myrealloc(void* arr, int& logSize, int& physize, int elemSize)
{
	void* newArr;
	newArr = new unsigned char[elemSize * physize];
	memcpy(newArr, (unsigned char*)arr, logSize * elemSize);
	delete arr;
	return newArr;
}