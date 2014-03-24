#include <iostream.h>

#include <stdio.h>

#include <conio.h>

#include <dos.h>

#include "MYCLOCK.H"

#include "MyMenu.h"

#include "NOWTIME.H"

#include "RINGTIME.H"

#include "BOOL.H"

const int speed = 999;

int main()
{
	RINGTIME ring_time;
	NOWTIME now_time;
	int hour, minute, second, year, month, day;
	char c;
	do
	{
		c = Menu("**********************\n"
				 "*N - Set NowTime_Date*\n"
				 "*R - Set RingTime    *\n"
				 "*S - Set EspecialDate*\n"
				 "*L - List All the Set*\n"
				 "*Q - End The Set     *\n"
				 "**********************\n"
				 "Choose:", "NRSLQ");
		switch(c)
		{
		case 'N':
			cout << "SetYear:"; cin >> year;
			now_time.Year(year);
			cout << "SetMonth:"; cin >> month;
			now_time.Month(month);
			cout << "SetDay:"; cin >> day;
			now_time.Day(day);
			cout << "SetHour:"; cin >> hour;
			now_time.Hour(hour);
			cout << "SetMinute:"; cin >> minute;
			now_time.Minute(minute);
			cout << "SetSecond:"; cin >> second;
			now_time.Second(second);
			
			break;
		case 'R':
			cout << "SetHour:"; cin >> hour;
			ring_time.Hour(hour);
			cout << "SetMinute:"; cin >> minute;
			ring_time.Minute(minute);
			cout << "TimeRemark:";
			ring_time.InputTime_Remark();
			break;
		case 'S':
			cout << "SetYear:"; cin >> year;
			ring_time.Year(year);
			cout << "SetMonth:"; cin >> month;
			ring_time.Month(month);
			cout << "SetDay:"; cin >> day;
			ring_time.Day(day);
			cout << "DateRemark:"; ring_time.InputDate_Remark();
			break;
		case 'L':
			cout << "NowTime:";
			now_time.OutputTime();
			now_time.OutputDate();
			cout << "RingTime:";
			ring_time.OutputTime();
			ring_time.OutputTime_Remark(); cout << endl;
			cout << "EspecialDate:\n";
			ring_time.OutputDate();
			ring_time.OutputDate_Remark(); cout << endl;
			break;
		}
	}
	while(c != 'Q');
	clrscr();
	while(!kbhit())
	{
		now_time.Increasement();
		now_time.OutputTime();
		now_time.OutputDate();
		ring_time.Ring(now_time);
		delay(speed);
		clrscr();
		//gotoxy(1, 1);
	}
	return 0;
}
