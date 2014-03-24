#include <iostream>

using namespace std;

#include "RESISTANCE.H"

RESISTANCE::RESISTANCE(double resistance):resistance(resistance) // 电阻初始化为2.5 , 电流和电压初始化0A和0V
{
	this->current = 0;
	this->voltage = 0;
}

double RESISTANCE::Resistance()const
{
	return this->resistance;
}

double RESISTANCE::Current()const
{
	return this->current;
}

double RESISTANCE::Voltage()const
{
	return this->voltage;
}

void RESISTANCE::Current(double current) // 电流设置为1.5A, 同时修改电压
{
	if(current >= 0) this->current = current, this->voltage = this->current * this->resistance;
	else cout << "不正确的参数!" << endl;
}

void RESISTANCE::Voltage(double voltage) //电压设置为3.5V, 同时修改电流
{
	if(voltage >= 0) this->voltage = voltage, this->current = this->voltage / this->resistance;
	else cout << "不正确的参数!" << endl;
}
