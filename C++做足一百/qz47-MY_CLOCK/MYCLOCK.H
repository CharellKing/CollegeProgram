#ifndef _MYCLOCK_H_

#define _MYCLOCK_H_

#include "MYDATE.H"

#include "MYTIME.H"

#include "BOOL.H"

class MYCLOCK
{
public:
	MYCLOCK();
	void Year(int year);
	int Year();
	void Month(int month);
	int Month();
	void Day(int day);
	int Day();
	void Hour(int hour);
	int Hour();
	void Minute(int minute);
	int Minute();
	void Second(int second);
	int Second();
	int MonthOfDay();
	void OutputTime();
	void OutputDate();
	void Increasement();
private:
	MYDATE pDate;
	MYTIME pTime;
};

#endif
