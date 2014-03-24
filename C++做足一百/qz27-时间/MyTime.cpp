#include <iostream>

#include "MyTime.h"

using namespace std;

void Input (TIME &x) // 输入时间数据
{
	int h, m, s;
	char d, e;
	while(cin >> h >> d >> m >> e >> s, !IsValid(h, m, s) || d != ':' || e != ':')
	cout << "ERROR! Input again\n";
	x.hour = h, x.minute = m, x.second = s;
}


	

void Output (const TIME &x) // 输出时间数据
{
	cout << (int)x.hour << ":" << (int)x.minute << ":" << (int)x.second << endl;
}


TIME Add (const TIME &x, int s) // 求时间x加s秒所得的时间(注: s为任意整数)
{
	TIME y;
	int ssum, h;
	ssum = x.hour * 3600 + x.minute * 60 + x.second + s;
	h = ssum / 3600;
	y.hour = h % 24;
	ssum -= h * 3600;
	y.minute = ssum / 60;
	y.second = ssum - y.minute * 60;
	return y;
}


TIME Sub (const TIME &x, int s) // 求时间x减s秒所得的时间(注: s为任意整数)
{
	TIME y;
	int ssum, h;
	ssum = x.hour * 3600 + x.minute * 60 + x.second - s;
	if(ssum < 0) ssum += 86400;
	h = ssum / 3600;
	y.hour = h % 24;
	ssum -= h * 3600;
	y.minute = ssum / 60;
	y.second = ssum - y.minute * 60;
	return y;

}

int Sub(const TIME &x, const TIME &y) // 求两个时间x和y之间相隔的秒数
{
	int ssum1, ssum2, delts;
	ssum1 = x.hour * 3600 + x.minute * 60 + x.second;
	ssum2 = y.hour * 3600 + y.minute * 60 + x.second;
	delts = ssum1 - ssum2;
	if(delts < 0) delts += 86400;
	return delts;
}

bool IsValid(int hour, int minute, int second) // 判断hour, minute, second是否为合法时间
{
	return (hour < 24 && hour >= 0 && minute < 60 && minute >= 0 && second < 60 && second >= 0);
}

//void Set(int hour, int minute, int second) // 设置时间

//void Get(int &hour, int &minute, int &second) // 获取时间
