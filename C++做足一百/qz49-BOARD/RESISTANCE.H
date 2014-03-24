#ifndef _RESISTANCE_H_

#define _RESISTANCE_H_

class RESISTANCE
{
public:
	RESISTANCE(double resistance = 1); // 电阻初始化为2.5 , 电流和电压初始化0A和0V
	double Resistance() const;
	double Current() const;
	double Voltage() const;
	void Current(double current); // 电流设置为1.5A, 同时修改电压
	void Voltage(double voltage); // 电压设置为3.5V, 同时修改电流
private:
	const double resistance;
	double current, voltage;
};
#endif