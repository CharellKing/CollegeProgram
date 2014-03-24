#include <iostream.h>

#include <iomanip.h>

#include "MYTIME.H"

#include "BOOL.H"

MYTIME::MYTIME()
{
	this->hour = 0, this->minute = 0, this->second = 0;
}

void MYTIME::Init()
{
	this->hour = 0, this->minute = 0, this->second = 0;
}

void MYTIME::Hour(int hour)
{
	if(hour >= 0 && hour < 24) this->hour = hour;
}

int MYTIME::Hour()
{
	return hour;
}


void MYTIME::Minute(int minute)
{
	if(minute >= 0 && minute < 60) this->minute = minute;
}

int MYTIME::Minute()
{
	return minute;
}

void MYTIME::Second(int second)
{
	if(second >= 0 && second < 60) this->second = second;
}

int MYTIME::Second()
{
	return second;
}

void MYTIME::Output()
{
	cout/* << right*/ << setfill('0')
		 << setw(2) << (int)hour << "-" << setw(2) << (int)minute << "-" << setw(2) << (int)second
		 << setfill(' ') << endl;
}

void MYTIME::SecondIncreasement()
{
	this->second ++;
}

void MYTIME::MinuteIncreasement()
{
	this->minute ++;
}

void MYTIME::HourIncreasement()
{
	this->hour ++;
}
