#ifndef _MYDATE_H
#define _MYDATE_H

class DATE
{
public:
	void Set(int y = 1, char m = 1, char d = 1);
	void Get(int &y, char &m, char &d);
	void Input();
	void Output(bool k = false);
private:
	int year;
	char month, day;
	bool IsValid(int y, char m, char d);
	char DayOfMonth(int y, char m);
	bool IsLeap(int y);
	char WeekDay(int y, char m, char d);
	int TotalDay(int y, char m, char d);
	int SumOfLeapYear(int y);
	int PastMonthDay(int y, char m);
};

#endif