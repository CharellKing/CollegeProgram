#include <iostream.h>

#include "MYCLOCK.H"

#include "BOOL.H"

MYCLOCK::MYCLOCK()
{
}

void MYCLOCK::Year(int year)
{
	this->pDate.Year(year);
}

int MYCLOCK::Year()
{
	return this->pDate.Year();
}

void MYCLOCK::Month(int month)
{
	this->pDate.Month(month);
}

int MYCLOCK::Month()
{
	return this->pDate.Month();
}

void MYCLOCK::Day(int day)
{
	this->pDate.Day(day);
}

int MYCLOCK::Day()
{
	return this->pDate.Day();
}

void MYCLOCK::Hour(int hour)
{
	this->pTime.Hour(hour);
}

int MYCLOCK::Hour()
{
	return this->pTime.Hour();
}
void MYCLOCK::Minute(int minute)
{
	this->pTime.Minute(minute);
}

int MYCLOCK::Minute()
{
	return this->pTime.Minute();
}
void MYCLOCK::Second(int second)
{
	this->pTime.Second(second);
}

int MYCLOCK::Second()
{
	return this->pTime.Second();
}

int MYCLOCK::MonthOfDay()
{
	return this->pDate.DayOfMonth(this->Year(), this->Month());
}

void MYCLOCK::OutputTime()
{
	this->pTime.Output();
}

void MYCLOCK::OutputDate()
{
	this->pDate.Output();
}

void MYCLOCK::Increasement()
{
	pTime.SecondIncreasement();
	if(60 == pTime.Second())
	{
		pTime.Second(0);
		pTime.MinuteIncreasement();
		if(60 == pTime.Minute())
		{
			pTime.Minute(0);
			pTime.HourIncreasement();
			if(24 == pTime.Hour())
			{
				pTime.Hour(0);
				pDate.DayIncreasement();
				if(pDate.Day() > MonthOfDay())
				{
					pDate.Day(1);
					pDate.MonthIncreasement();
					if(12 < pDate.Month())
					{
						pDate.Month(1);
						pDate.YearIncreasement();
					}
				}
			}
		}
	}
}