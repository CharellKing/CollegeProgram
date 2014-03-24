#ifndef _MYDATE_H_

#define _MYDATE_H_

struct DATE
{
	int year;
	char month, day;
};

inline bool IsLeap(int year)
{
	return 0 == year % 4 && year % 100 || 0 == year % 400;
}


char DayOfMonth(int year, char month);

inline bool IsValid(int y, char m, char d)
{
	return y > 0 && m > 0 && m <= 12 && d > 0 && d <= DayOfMonth(y, m);
}

void InputDate(DATE &x);

void OutputDate(const DATE &x, bool isPrintweekday = false);

int LeapSum(int year);

int	TheYearPastDay(const DATE &x);

int TotalOfDay(const DATE &x);

int Week(const DATE &x);

char DayOfMonth(int year, char month);


#endif