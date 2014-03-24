#include <iostream.h>

#include <iomanip.h>

#include "MYDATE.H"


#include "BOOL.H"

MYDATE::MYDATE()
{
	this->day = 1, this->month = 1, this->year = 1;
}

void MYDATE::Init()
{
	this->day = 1, this->month = 1, this->year = 1;
}

int MYDATE::DayOfMonth(int year, int month)
{
	int month_day;
	const static char day_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	month_day = day_of_month[month - 1];
	if(month == 2 && IsLeap(year)) month_day ++;
	return month_day;
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

void MYDATE::Year(int year)
{
	if(year > 0) this->year = year;
}

int MYDATE::Year()
{
	return year;
}

void MYDATE::Month(int month)
{
	if(month > 0 && month <= 12) this->month = month;
}

int MYDATE::Month()
{
	return month;
}

void MYDATE::Day(int day)
{
	if(day > 0 && day <= DayOfMonth(this->year, this->month)) this->day = day;
}

int MYDATE::Day()
{
	return day;
}

void MYDATE::Output()
{
	const static char *weekday[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	cout //<< right
		 << year << "-" << setfill('0') << setw(2) << (int)month << "-" << setw(2) << (int)day
		 << "(" << weekday[Weekday(year, month, day)] << ")"
		 << setfill(' ') << endl;
}

void MYDATE::DayIncreasement()
{
	this->day ++;
}

void MYDATE::MonthIncreasement()
{
	this->month ++;
}
void MYDATE::YearIncreasement()
{
	this->year ++;
}