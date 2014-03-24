#include <iostream>

using namespace std;

#include <iomanip>

#include "MYDATE.H"

int MYDATE::DayOfMonth(int year, int month)
{
	int month_day;
	const static char day_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	month_day = day_of_month[month - 1];
	if(month == 2 && IsLeap(year)) month_day ++;
	return month_day;
}

void MYDATE::Input()
{
	char c1, c2;
	int year, month, day;
	cout << "输入方式(1988-10-1):";
	while(cin >> year >> c1 >> month >> c2 >> day, c1 != '-' || c2 != '-' || !IsValid(year, month, day) || (!cin))
	{
		if(!cin)
		{
			cin.clear();
			cin.sync();
		}
		cout << "重新输入!" << endl;
	}
	this->year = year, this->month = month, this->day = day;
}

bool MYDATE::IsValid(int year, int month, int day)
{
	return year >= 1 && month >= 1 && month <= 12 && day >= 0 && day <= DayOfMonth(year, month);
}

bool MYDATE::IsLeap(int year)
{
	return 0 == year % 4 && year % 100 || 0 == year % 400;
}

int MYDATE::Weekday(int year, int month, int day)
{
	return TotalDay(year, month, day) % 7;
}

int MYDATE::Sum_Of_Leap(int year)
{
	return year / 4 - year / 100 + year / 400;
}

int MYDATE::TotalDay(int year, int month, int day)
{
	return 365 * (year - 1) + Sum_Of_Leap(year - 1) + Year_Total_Day(year, month, day);
}

int MYDATE::Year_Total_Day(int year, int month, int day)
{
	int sum;
	const static int sum_of_year_day[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	sum = sum_of_year_day[month-1] + day;
	if(IsLeap(year) && month > 2) sum ++;
	return sum;
}

void MYDATE::Output()
{
	const static char *weekday[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	cout //<< right
		 << year << "-" << setfill('0') << setw(2) << (int)month << "-" << setw(2) << (int)day
		 << "(" << weekday[Weekday(year, month, day)] << ")"
		 << setfill(' ') << endl;
}
