#include <iostream.h>

#include <stdio.h>

#include "RINGTIME.H"

#include "BOOL.H"

RINGTIME::RINGTIME()
{
	this->time_remark[0] = '\0';
	this->date_remark[0] = '\0';
}

void RINGTIME::InputTime_Remark()
{
	char c, i = 0;
	while(c = getchar(), c != 10 && i < length -1) this->time_remark[i ++] = c;
	this->time_remark[i] = '\0';
}

void RINGTIME::InputDate_Remark()
{
	char c, i = 0;
	while(c = getchar(),  c != 10 && i < length - 1) this->date_remark[i ++] = c;
	this->date_remark[i] = '\0';
}

void RINGTIME::OutputDate_Remark()
{
	char i = 0;
	while(this->date_remark[i]) cout << this->date_remark[i++];
	if(i) cout << endl;
}
void RINGTIME::OutputTime_Remark()
{
	char i = 0;
	while(this->time_remark[i]) cout << this->time_remark[i++];
	if(i) cout << endl;
}

void RINGTIME::Ring(const NOWTIME &x)
{
	pNow_time = x;
	if(pNow_time.Minute() == Minute() && pNow_time.Hour() == Hour()) putchar('\a'),OutputTime_Remark();
	if(pNow_time.Day() == Day() && pNow_time.Month() == Month() && pNow_time.Year() == Year()) OutputDate_Remark();
}
