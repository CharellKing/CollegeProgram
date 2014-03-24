//1.	时间
//设计时间结构类型TIME, 它包含三个成员: hour、minute和second, 分别表示时、分和秒。设计下面的函数:
//void Input (TIME &x); // 输入时间数据
//void Output (const TIME &x); // 输出时间数据
//TIME Add (const TIME &x, int s); // 求时间x加s秒所得的时间(注: s为任意整数)
//TIME Sub (const TIME &x, int s); // 求时间x减s秒所得的时间(注: s为任意整数)
//int Sub(const TIME &x, const TIME &y); // 求两个时间x和y之间相隔的秒数
//bool IsValid(int hout, int minute, int second); // 判断hour, minute, second是否为合法时间
//void Set(int hour, int minute, int second); // 设置时间
//void Get(int &hour, int &minute, int &second); // 获取时间

#include <iostream>

#include <conio.h>

#include "MyTime.h"

using namespace std;

int main()
{
	TIME time1, time2;
	int s;
	cout << "Please input the time in the way(23:45:56)\n";
	Input (time1); // 输入时间数据
	Output (time1); // 输出时间数据
	cout << "Please input the seconds you add:\n";
	cin >> s;
	Output(Add (time1, s)); // 求时间x加s秒所得的时间(注: s为任意整数)
	Output(Sub (time1, s)); // 求时间x减s秒所得的时间(注: s为任意整数)
	Input (time2); // 输入时间数据
	Output (time2); // 输出时间数据
	cout << "deltSecond:" << Sub(time1, time2) << endl; // 求两个时间x和y之间相隔的秒数
	Set(int hour, int minute, int second); // 设置时间

	getch();
	return 0;
}
	
