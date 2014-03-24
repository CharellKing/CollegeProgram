#include <iostream>

using namespace std;

#include "BOARD.H"

BOARD::BOARD(double resistance1, double resistance2, double resistance3): r1(resistance1), r2(resistance2), r3(resistance3)
{
}

double BOARD::Resistance1()	// 读取第1个电阻的阻值
{
	return r1.Resistance();
}

double BOARD::Resistance2()	// 读取第2个电阻的阻值
{
		return r2.Resistance();
}

double BOARD::Resistance3()	// 读取第3个电阻的阻值
{
	return r3.Resistance();
}

double BOARD::Current1()	// 读取第1个电阻上的电流
{
	return r1.Current();
}
double BOARD::Current2()	// 读取第2个电阻上的电流
{
	return r2.Current();
}

double BOARD::Current3()	// 读取第3个电阻上的电流
{
	return r3.Current();
}

double BOARD::Voltage1()	// 读取第1个电阻上的电压
{
	return r1.Voltage();
}

double BOARD::Voltage2()	// 读取第1个电阻上的电压
{
	return r2.Voltage();
}

double BOARD::Voltage3()	// 读取第1个电阻上的电压
{
	return r3.Voltage();
}

double BOARD::Resistance()	// 读取总电阻
{
	return r1.Resistance() + r2.Resistance() * r3.Resistance() / (r2.Resistance() + r3.Resistance());
}

double BOARD::Current()	// 读取总电流
{
	return Current1();
}

double BOARD::Voltage()   //读取总电压
{
	return Voltage1() + Voltage2();
}

void BOARD::Current(double current)
{
	r1.Current(current);
	r2.Current(r3.Resistance() * current / (r2.Resistance() + r3.Resistance()));
	r3.Current(r1.Current() - r2.Current());
}

void BOARD::Voltage(double voltage)
{
	r1.Current(voltage / Resistance());
	r2.Voltage(voltage - r1.Voltage());
	r3.Voltage(r2.Voltage());
}

