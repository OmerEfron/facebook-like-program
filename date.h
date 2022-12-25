#ifndef DATE_H
#define DATE_H


class Date
{
private:
	int _day, _month, _year;
public:
	Date();
	Date(int day, int month, int year);
	int getDay() const;
	int getMonth()const;
	int getYear()const;
	void showDate() const;

};
#endif // !DATE_H