#ifndef _MYTIME_H

#define _MYTIME_H

struct TIME
{
	char hour, minute, second;
};

void Input (TIME &x); // 输入时间数据

void Output (const TIME &x); // 输出时间数据

TIME Add (const TIME &x, int s); // 求时间x加s秒所得的时间(注: s为任意整数)

TIME Sub (const TIME &x, int s); // 求时间x减s秒所得的时间(注: s为任意整数)

int Sub(const TIME &x, const TIME &y); // 求两个时间x和y之间相隔的秒数

bool IsValid(int hout, int minute, int second); // 判断hour, minute, second是否为合法时间

void Set(int hour, int minute, int second); // 设置时间

void Get(int &hour, int &minute, int &second); // 获取时间

#endif