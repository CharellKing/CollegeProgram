#ifndef _MYDATE_H_

#define _MYDATE_H_

class MYDATE
{
public:
	MYDATE(int yeat = 1, int month = 1, int day = 1);
	void InputDate();
	void OutputDate(bool isPrintweekday = false) const;
private:
	static int TotalOfDay(int year, int month, int day);
	static int Week(int year, int month, int day);
	static int	TheYearPastDay(int year, int month, int day);
	static int LeapSum(int year);
	static bool IsValid(int year, int month, int day);
	static char DayOfMonth(int year, char month);
	static bool IsLeap(int year);
	int year;
	char month, day;
};



#endif