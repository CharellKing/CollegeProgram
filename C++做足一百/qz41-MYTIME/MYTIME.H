#ifndef _MYTIME_H_

#define _MYTIME_H_

class MYTIME
{
public:
	MYTIME();
	~MYTIME()
	{
	}
	void Output(bool b = false);
	void Input();
	void Set(int hour = 0, int minute = 0, int second = 0);
	void Get(int &hour, int &minute, int &second);
	int Hour();
	int Minute();
	int Second();
	void Hour(int hour);   // 仅设置时
	void Minute(int minute); // 仅设置分
	void Second(int second); // 仅设置秒

private:
	bool IsValid(int hour, int minute, int second);
	char hour, minute, second;
};

#endif