//将实验3中的时间结构改进为时间类, 它包括三个私有数据成员: hour、minute和second, 分别表示时、分和秒。
//然后设计Input(输入)、Output(输出)、Set(设置)、Get(读取)、Hour(时读写)、Minute(分读写)、Second(秒读写)等公有成员函数, 
//完成以下基本功能: 
#include <iostream>

using namespace std;

#include "MYTIME.H"

int main()
{
	MYTIME a;
	a.Set(8, 10, 15);
	cout << a.Hour() << endl;
	cout << a.Minute() << endl;
	cout << a.Second() << endl;
	a.Hour(21);   // 仅设置时
	cout << "a = "; a.Output(); cout << endl;
	a.Minute(40); // 仅设置分
	cout << "a = "; a.Output(); cout << endl;
	a.Second(45); // 仅设置秒
	cout << "a = "; a.Output(); cout << endl;
	a.Hour(87);    // 参数错误(不起作用)
	a.Minute(-45); // 参数错误(不起作用)
	a.Second(100); // 参数错误(不起作用)
	cout << "a = "; a.Output(); cout << endl;
	return 0;
}
