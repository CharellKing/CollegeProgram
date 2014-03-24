#ifndef _MYDATE_H_

#define  _MYDATE_H_

#include "BOOL.H"

class MYDATE
{
public:
	MYDATE();
	void Init();
	void Year(int year);
	int Year();
	void Month(int month);
	int Month();
	void Day(int day);
	int Day();
	void Output();
	int DayOfMonth(int year, int month);
	void DayIncreasement();
	void MonthIncreasement();
	void YearIncreasement();	
private:
	int TotalDay(int year, int month, int day);
	int Sum_Of_Leap(int year);
	int Year_Total_Day(int year, int month, int day);
	bool IsLeap(int year);
	int Weekday(int year, int month, int day);
	int year;
	char month, day;
};

#endif