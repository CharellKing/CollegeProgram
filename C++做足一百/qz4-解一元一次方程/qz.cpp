//4.	解一元一次方程: ax + b = 0
//输入系数a和常数b, 输出方程的解。
//要求: 讨论所有可能的情况, 测试数据如下:
//2x - 1 = 0	x = 0.5
//0x + 2 = 0	无解
//0x + 0 = 0	无穷多解

#include <iostream>

using namespace std;

int main()
{
	float a, b;
	cout << "There is a simple equation: ax + b = 0." << endl;
	cout << "Please input the quotiety of a factor \"a\" and a constant \"b\"" << endl;
	cin >> a >> b;
	if(0 == a)
	{
		if(0 == b)
		{
			cout << "There are endless equations!\n";
		}
		else
		{
			cout << "There is no equation!\n";
		}
	}
	else
	{
		cout << "There is only a equation:" << endl;
		cout << -b / a << endl;
	}
	return 0;
}
