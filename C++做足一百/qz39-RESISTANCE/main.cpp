#include <iostream>

using namespace std;

#include "RESISTANCE.H"

void Test1();

void Test2();

int main()
{
	Test1();
	Test2();
	return 0;
}

void Test1()
{
	RESISTANCE a; // 创建阻值为1 的电阻, 将电流和电压初始化0A和0V
	a.Current(1); // 电流设置为1A
	cout << "阻值: " << a.Resistance() << endl;
	cout << "电流: " << a.Current() << endl;
	cout << "电压: " << a.Voltage() << endl;
}

void Test2()
{
	RESISTANCE b(2.5); // 创建阻值为2.5 的电阻, 将电流和电压初始化0A和0V
	b.Voltage(3.5);    // 电压设置为3.5V
	cout << "阻值: " << b.Resistance() << endl;
	cout << "电流: " << b.Current() << endl;
	cout << "电压: " << b.Voltage() << endl;
}
