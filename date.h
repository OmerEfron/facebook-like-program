#ifndef DATE_H
#define DATE_H


class Date
{
private:
	int _day, _month, _year;
public:
	Date();
	Date(int day, int month, int year);
	int getDay();
	int getMonth();
	int getYear();
	void showDate() const;

};
#endif // !DATE_H