#include <iostream>

using namespace std;

#include <iomanip>

#include "MyDate.h"

bool DATE::IsValid(int y, char m, char d)
{
	return y >= 0 && m >= 0 && m <= 12 && d >= 0 && d <= DayOfMonth(y, m);
}

char DATE::DayOfMonth(int y, char m)
{
	static const char MonthDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char d;
	d = MonthDay[m - 1];
	if(m == 2 && IsLeap(y)) d ++;
	return d;
}

bool DATE::IsLeap(int y)
{
	return 0 == y % 4 && y % 100 || 0 == y % 400;
}


void DATE::Set(int y, char m, char d)
{
	year = y; month = m; day = d;
}

void DATE::Get(int &y, char &m, char &d)
{
	y = year, m = month, d = day;
}

void DATE::Input()
{
	int y, m, d;
	char a, b;
	bool k;
	while(k = !(cin >> y >> a >> m >> b >> d) || !IsValid(y, m, d) || a != '-' || b != '-')
	{
		if(k)
		{
			cin.clear();
			cin.ignore(1024, '\n');
		}
		cout << "不正确的时间日期，请重新输入:";
	}
	year = y, month = m, day = d;
}


void DATE::Output(bool k)
{
	static const char *weekday[] = {"日", "一", "二", "三", "四", "五", "六"};
	char week;
	week = WeekDay(year, month, day);
	cout << year << '-' << setfill('0') << setw(2) << (int)month << '-' << setw(2) << (int)day;
	if(k) cout << "(星期" << weekday[week] << ")";
}

char DATE::WeekDay(int y, char m, char d)
{
	return TotalDay(y, m, d) % 7;
}

int DATE::TotalDay(int y, char m, char d)
{
	return (y - 1) * 365 + SumOfLeapYear(y - 1) + PastMonthDay(y , m) + d;
}

int DATE::SumOfLeapYear(int y)
{
	return y / 4 - y / 100 + y / 400;
}

int DATE::PastMonthDay(int y, char m)
{
	static int const d[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304};
	int s;
	s = d[m - 1];
	if(m > 2) s ++;
	return s;
}










