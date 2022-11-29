#define _CRT_SECURE_NO_WARNINGS
#include "member.h"
#include "date.h"
#include "status.h"
#include "functions.h"

int main()
{
	char name[7] = "shafir";
	Member shafir(name, Date(9, 6, 97));
	Status status(name, Date(9, 6, 97), Time(7, 30));

	shafir.addStatus(status);


}