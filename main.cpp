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
	char statusStr[3][10] = { "Yala HBS" , "Yarok Ole", "Maccaki"};
	char fanPageStr[2][11] = { "Green Apes" , "Vasermilia"};;
	Member efron(name[1], Date(22, 7, 97));
	Member shafir(name[0], Date(2, 5, 98));
	Member ohad(name[2], Date(1, 1, 97));
	Member roni(name[3], Date(2, 2, 97));
	Status status1(statusStr[0], Date(9, 6, 2021), Time(7, 30));
	Status status2(statusStr[1], Date(8, 7, 2020), Time(15, 17));
	Status status3(statusStr[2], Date(9, 2, 2022), Time(17, 2));
	FanPage mhod(fanPageStr[0]);
	FanPage vs(fanPageStr[1]);
	facebook.addMember(efron);
	facebook.addMember(shafir);
	facebook.addMember(ohad);
	facebook.addMember(roni);
	facebook.addPage(vs);
	facebook.addPage(mhod);
	efron.addStatus(status1);
	shafir.addStatus(status2);
	roni.addStatus(status3);

	while (getChoice(facebook))
	{
		cout << "\n----------------------\n";
		continue;
	}
}