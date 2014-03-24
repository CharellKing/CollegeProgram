#include <iostream>

using namespace std;

#include <iomanip>

#include "MyDate.h"

int LeapSum(int year)
{
	return year / 4 - year / 100 + year / 400;
}

int	TheYearPastDay(const DATE &x)
{
	int passMonthday[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304};
	return passMonthday[x.month -1] + x.day;
}


int TotalOfDay(const DATE &x)
{
	return 365 * (x.year - 1) + LeapSum(x.year - 1) + TheYearPastDay(x);
}

int Week(const DATE &x)
{
	return TotalOfDay(x) % 7;
}

char DayOfMonth(int year, char month)
{
	char s;
	const static char dayOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(month >= 0 && month <= 12)
	{
		s = dayOfMonth[month - 1];
		if(IsLeap(year) && month == 2) s ++;
	}
	return s;
}	


void InputDate(DATE &x)
{
	int y, m, d; 
	char a, b;
	while(!(cin >> y >> a >> m >> b >> d) || a != '-' || b != '-' || !IsValid(y, m, d))
	{
		if(!cin.good()) cin.clear();
		while(cin.get() != '\n');
		cout << "ERROR! INPUT AGAIN!\n";
	}
	x.year = y, x.month = m, x.day = d;
}

void OutputDate(const DATE &x, bool isPrintweekday)
{
	const static char *weekday[] = {"日", "一", "二", "三", "四", "五", "六"};
	cout << x.year <<setfill('0') << '-' << setw(2) << (int)x.month << '-' << setw(2) << (int)x.day << setfill(' ');
	if(isPrintweekday) cout << "(星期" << weekday[Week(x)] << ")";
	cout << endl;
}

