#ifndef DATE_H
#define DATE_H


class Date
{
private:
	int day, month, year;

public:
	Date(int d, int m, int y);
	int getDay();
	int getMonth();
	int getYear();
	void showDate();

};
#endif // !DATE_H