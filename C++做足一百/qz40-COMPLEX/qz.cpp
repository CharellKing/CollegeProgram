//2.	复数类(MYCOMPLEX)
//设计复数类, 它包括两个私有数据成员: real和imaginary, 分别表示实数和虚部系数。
//请为该类设计公有成员函数, 完成以下基本功能: 
#include <iostream>

using namespace std;

#include "COMPLEX.H"

void Test(COMPLEX x);

COMPLEX Test(double r, double i);

int main()
{
	COMPLEX a;
	cout << "a = "; a.Output(); cout << endl;
	a = Test(3, 4);
	cout << "a = "; a.Output(); cout << endl;
	return 0;
}

COMPLEX Test(double r, double i)
{
	COMPLEX x;
	x.Set(r, i);
	return x;
}




