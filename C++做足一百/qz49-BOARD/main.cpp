#include <iostream>

using namespace std;

#include "RESISTANCE.H"

#include "BOARD.H"

int main()
{
	/*const*/BOARD a(3, 4, 5); // 创建三个电阻分别为3 、4 和5 电路板
	cout << a.Resistance1() << endl;	// 读取第1个电阻的阻值
	cout << a.Resistance2() << endl;	// 读取第2个电阻的阻值
	cout << a.Resistance3() << endl;	// 读取第3个电阻的阻值
	cout << a.Current1() << endl;	// 读取第1个电阻上的电流
	cout << a.Current2() << endl;	// 读取第2个电阻上的电流
	cout << a.Current3() << endl;	// 读取第3个电阻上的电流
	cout << a.Voltage1() << endl;	// 读取第1个电阻上的电压
	cout << a.Voltage2() << endl;	// 读取第1个电阻上的电压
	cout << a.Voltage3() << endl;	// 读取第1个电阻上的电压
	cout << a.Resistance() << endl;	// 读取总电阻
	cout << a.Current() << endl;	// 读取总电流
	cout << a.Voltage() << endl;	// 读取总电压

	a.Current(1.5);	// 给电路板加上1.5A电流
	cout << a.Resistance1() << endl;	// 读取第1个电阻的阻值
	cout << a.Resistance2() << endl;	// 读取第2个电阻的阻值
	cout << a.Resistance3() << endl;	// 读取第3个电阻的阻值
	cout << a.Current1() << endl;	// 读取第1个电阻上的电流
	cout << a.Current2() << endl;	// 读取第2个电阻上的电流
	cout << a.Current3() << endl;	// 读取第3个电阻上的电流
	cout << a.Voltage1() << endl;	// 读取第1个电阻上的电压
	cout << a.Voltage2() << endl;	// 读取第1个电阻上的电压
	cout << a.Voltage3() << endl;	// 读取第1个电阻上的电压
	cout << a.Resistance() << endl;	// 读取总电阻
	cout << a.Current() << endl;	// 读取总电流
	cout << a.Voltage() << endl;	// 读取总电压

	a.Voltage(3.5);	// 给电路板加上3.5V电压
	cout << a.Resistance1() << endl;	// 读取第1个电阻的阻值
	cout << a.Resistance2() << endl;	// 读取第2个电阻的阻值
	cout << a.Resistance3() << endl;	// 读取第3个电阻的阻值
	cout << a.Current1() << endl;	// 读取第1个电阻上的电流
	cout << a.Current2() << endl;	// 读取第2个电阻上的电流
	cout << a.Current3() << endl;	// 读取第3个电阻上的电流
	cout << a.Voltage1() << endl;	// 读取第1个电阻上的电压
	cout << a.Voltage2() << endl;	// 读取第1个电阻上的电压
	cout << a.Voltage3() << endl;	// 读取第1个电阻上的电压
	cout << a.Resistance() << endl;	// 读取总电阻
	cout << a.Current() << endl;	// 读取总电流
	cout << a.Voltage() << endl;	// 读取总电压
	return 0;
}	

