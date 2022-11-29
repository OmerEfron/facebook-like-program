#ifndef TIME_H
#define TIME_H

class Time
{
private:
	int hour, minutes;

public:
	Time(int h, int m);
	int getHours();
	int getMinutes();
	void showHour();

};
#endif // !TIME_H