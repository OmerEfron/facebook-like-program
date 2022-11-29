#define _CRT_SECURE_NO_WARNINGS
#include "member.h"
#include "date.h"
#include "status.h"
#include "functions.h"

int main()
{
	char name[4][8] = { "shafir", "efron", "ohad", "ronald"};
	char statusStr[10] = "Yala HBS";
	char fanPageStr[11] = "Green Apes";
	Member shafir(name[0], Date(9, 6, 97));
	Member efron(name[1], Date(22, 7, 97));
	Member ohad(name[2], Date(1, 1, 97));
	Member roni(name[3], Date(2, 2, 97));
	Status status(statusStr, Date(9, 6, 97), Time(7, 30));
	FanPage mhod(fanPageStr);
	efron.addFriend(&shafir);
	efron.removeFriend(&shafir);
	ohad.addFriend(&efron);
	roni.removeFriend(&shafir);
	shafir.addStatus(status);
	shafir.removeFriend(&ohad);
	roni.addPage(&mhod);
	efron.addPage(&mhod);
	shafir.removePage(&mhod);
	efron.removePage(&mhod);
}