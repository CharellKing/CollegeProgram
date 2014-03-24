#ifndef _RINGTIME_H_

#define  _RINGTIME_H_

#include "MYCLOCK.H"

#include "NOWTIME.H"

#include "BOOL.H"

const int length = 15;

const int ring_time_lenght = 5;//·Ö

class RINGTIME: public MYCLOCK
{
public:
	RINGTIME();
	~RINGTIME(){}
	void InputDate_Remark();
	void InputTime_Remark();
	void OutputDate_Remark();
	void OutputTime_Remark();
	void Ring(const NOWTIME &x);
private:
	char date_remark[length], time_remark[length];
	NOWTIME pNow_time;
};

#endif