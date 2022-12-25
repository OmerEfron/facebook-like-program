#define _CRT_SECURE_NO_WARNINGS
#include "member.h"
#include "date.h"
#include "status.h"
#include "functions.h"
#include "facebook.h"
#include <iostream>
using namespace std;
int main()
{
	Facebook facebook;


	char name[4][8] = { "shafir", "efron", "ohad", "ronald"};
	char statusStr[10][15] = { "Yala HBS" , "Yarok Ole", "Hakuna Matata", "Ma Nishma?", "Tnu Like", "My Status", 
	"Efron The King", "Shaf Shaf 6", "MHOD", "THIS IS TERNER"};
	char fanPageStr[2][11] = { "Green Apes" , "Vasermilia"};;
	Member efron(name[1], Date(22, 7, 97));
	Member shafir(name[0], Date(2, 5, 98));
	Member ohad(name[2], Date(1, 1, 97));
	Member roni(name[3], Date(2, 2, 97));
	Status status1(statusStr[0], Date(), Time());
	Status status2(statusStr[1], Date(), Time());
	Status status3(statusStr[2], Date(), Time());
	Status status4(statusStr[3], Date(), Time());
	Status status5(statusStr[4], Date(), Time());
	Status status6(statusStr[5], Date(), Time());
	FanPage mhod(fanPageStr[0]);
	FanPage vs(fanPageStr[1]);
	//efron += shafir;
	if (efron > shafir)
	{
		return 0;
	}
	facebook.addMember(efron);
	facebook.addMember(shafir);
	facebook.addMember(ohad);
	facebook.addMember(roni);
	facebook.addPage(vs);
	facebook.addPage(mhod);
	efron.addStatus(status1);
	shafir.addStatus(status2);
	roni.addStatus(status3);
	roni.addFriend(&efron);
	efron.addFriend(&shafir);
	shafir.addFriend(&roni);
	ohad.addFriend(&efron);
	mhod.addFan(&ohad);
	mhod.addFan(&shafir);
	vs.addFan(&efron);
	vs.addFan(&roni);

	while (getChoice(facebook))
	{
		cout << "\n----------------------\n";
		continue;
	}
}