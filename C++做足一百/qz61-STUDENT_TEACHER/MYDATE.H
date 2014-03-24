#ifndef _MYDATE_H_

#define  _MYDATE_H_

class MYDATE
{
public:
	void Input();
	void Output();
private:
	static bool IsValid(int year, int month, int day);
	static int DayOfMonth(int year, int month);
	static int TotalDay(int year, int month, int day);
	static int Sum_Of_Leap(int year);
	static int Year_Total_Day(int year, int month, int day);
	static bool IsLeap(int year);
	static int Weekday(int year, int month, int day);
	int year;
	char month, day;
};

#endif