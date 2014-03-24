#include <iostream>

using namespace std;

#include <iomanip>

#include "MYTIME.H"

MYTIME::MYTIME()
{
	hour = 0, minute = 0, second = 0;
}

void MYTIME::Output(bool b)
{
	cout << setfill('0') << setw(2) << (int)hour << ':' << setw(2) << (int)minute << ":" << setw(2) << (int)second;
	if(b)
	{
		if(hour > 12) cout << "(下午)";
		else cout << "(上午)";
	}
}
	
void MYTIME::Input()
{
	int hour, minute, second;
	char c, d;
	while(!(cin >> hour >> c >> minute >> d >> second) || !IsValid(hour, second, minute) || c != ':' || d != c)
	{
		if(!cin.good())
		{
			cin.clear();
			while(cin.get() != '\n');
		}
		cout << "不正确的时间，请重新输入:";
	}
	this->hour = hour, this->minute = minute, this->second = second;
}

bool MYTIME::IsValid(int hour, int minute, int second)
{
	return hour >= 0 && hour < 24 && minute >= 0 && minute < 60 && second >= 0 && second < 60;
}

void MYTIME::Set(int hour, int minute, int second)
{
	if(IsValid(hour, minute, second)) this->hour = hour, this->minute = minute, this->second = second;
	else cout << "不正确的参数!" << endl;
}

void MYTIME::Get(int &hour, int &minute, int &second)
{
	hour = this->hour, minute = this->minute, second = this->second;
}

int MYTIME::Hour()
{
	return hour;
}

int MYTIME::Minute()
{
	return minute;
}

int MYTIME::Second()
{
	return second;
}

void MYTIME::Hour(int hour)   // 仅设置时
{
	if(hour >= 0 && hour < 24) this->hour = hour;
	else cout << "不正确的参数!" << endl;
}

void MYTIME::Minute(int minute) // 仅设置分
{
	if(minute >= 0 && minute < 60) this->minute = minute;
	else cout << "不正确的参数!" << endl;
}

void MYTIME::Second(int second) // 仅设置秒
{
	if(second >= 0 && second < 60) this->second = second;
	else cout << "不正确的参数!" << endl;
}
