#include <iostream>

using namespace std;

#include <iomanip>

#include "MyDate.h"

MYDATE::MYDATE(int year, int month ,int day)
{
	this->day = day, this->month = month, this->year = year;
}

int MYDATE::LeapSum(int year)
{
	return year / 4 - year / 100 + year / 400;
}

int	MYDATE::TheYearPastDay(int year, int month, int day)
{
	int passMonthday[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304};
	return passMonthday[month -1] + day;
}


int MYDATE::TotalOfDay(int year, int month, int day)
{
	return 365 * (year - 1) + LeapSum(year - 1) + TheYearPastDay(year, month, day);
}

int MYDATE::Week(int year, int month, int day)
{
	return TotalOfDay(year, month, day) % 7;
}

char MYDATE::DayOfMonth(int year, char month)
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


void MYDATE::InputDate()
{
	int year, month, day; 
	char a, b;
	while(!(cin >> year >> a >> month >> b >> day) || a != '-' || b != '-' || !IsValid(year, month, day))
	{
		if(!cin.good()) cin.clear();
		while(cin.get() != '\n');
		cout << "ERROR! INPUT AGAIN!\n";
	}
	this->year = year, this->month = month, this->day = day;
}

void MYDATE::OutputDate(bool isPrintweekday) const
{
	const static char *weekday[] = {"日", "一", "二", "三", "四", "五", "六"};
	cout << year <<setfill('0') << '-' << setw(2) << (int)month << '-' << setw(2) << (int)day << setfill(' ');
	if(isPrintweekday) cout << "(星期" << weekday[Week(year, month, day)] << ")";
	cout << endl;
}

bool MYDATE::IsValid(int year, int month, int day)
{
	return year > 0 && month > 0 && month <= 12 && day > 0 && day <= DayOfMonth(year, month);
}

bool MYDATE::IsLeap(int year)
{
	return 0 == year % 4 && year % 100 || 0 == year % 400;
}