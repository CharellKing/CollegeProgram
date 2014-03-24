/*
	设计复数类, 它包含两个私有数据成员: real和imaginary, 分别表示实数和虚部系数。
*/

#include <iostream>
using namespace std;
#include "MyComplex.h"

int main()
{
	MYCOMPLEX a, b, c, d, e, f;
	cout << "a = ? "; cin >> a;
	cout << "b = ? "; cin >> b;
	c = a + b;
	d = a - b;
	e = a * b;
	f = a / b;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "e = " << e << endl;
	cout << "f = " << f << endl;
	return 0;
}
