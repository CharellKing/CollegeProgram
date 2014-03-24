#ifndef _MYTIME_H_

#define  _MYTIME_H_

class MYTIME
{
public:
	MYTIME();
	void Init();
	void Output();
	void Hour(int hour);
	int Hour();
	void Minute(int minute);
	int Minute();
	void Second(int second);
	int Second();
	void SecondIncreasement();
	void MinuteIncreasement();
	void HourIncreasement();
private:
	char hour, minute, second;
};


#endif