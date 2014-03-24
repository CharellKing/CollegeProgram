#ifndef _BOARD_H_

#define  _BOARD_H_

#include "RESISTANCE.H"

class BOARD
{
public:
	BOARD(double resistance1, double resistance2, double resistance3);
	double Resistance1();	// 读取第1个电阻的阻值
	double Resistance2();	// 读取第2个电阻的阻值
	double Resistance3();	// 读取第3个电阻的阻值
	double Current1();	// 读取第1个电阻上的电流
	double Current2();	// 读取第2个电阻上的电流
	double Current3();	// 读取第3个电阻上的电流
	double Voltage1();	// 读取第1个电阻上的电压
	double Voltage2();	// 读取第1个电阻上的电压
	double Voltage3();	// 读取第1个电阻上的电压
	double Resistance();	// 读取总电阻
	double Current();	// 读取总电流
	double Voltage();   //读取总电*/
	void Current(double current);
	void Voltage(double voltage);
private:
	RESISTANCE r1, r2, r3;
};

#endif
