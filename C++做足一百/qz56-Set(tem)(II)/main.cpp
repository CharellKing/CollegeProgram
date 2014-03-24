//1.	集合类(一):
//设计实数集合类(MYSET), 包含两个数据成员, 一个是指向动态实数数组的指针elements, 
//一个是基合的基数cardinal, 一个是数组的尺寸size。请为该类设计构造函数、析构函数, 
//以及公有成员函数Cardinal(集合基数)、IsEmpty(判断空集)、Append(添加元素)、Remove(删除元素)、
//Clear(清空集合)、Find(查找元素)、Exist(判断元素)、Get(读取元素)、Input(输入集合)
//和Output(输出集合)等, 完成以下功能:

#include <iostream>

using namespace std;

#include "MYSET.H"

int main()
{
	MYSET<double> a, b, c, d, e;
	a.Append(2); a.Append(4); a.Append(6);
	a.Append(8); a.Append(10);
	cout << "a = "; a.Output(); cout << endl;

	b.Append(3); b.Append(6); b.Append(9);
	cout << "b = "; b.Output(); cout << endl;

	c.Append(4); c.Append(8);
	cout << "c = "; c.Output(); cout << endl;
	c = a.Add(b); // 求a和b的并集
	cout << "c = "; c.Output(); cout << endl;

	d.Append(5); d.Append(10);
	cout << "d = "; d.Output(); cout << endl;
	d = a.Mul(b); //求a和b的交集
	cout << "d = "; d.Output(); cout << endl;

	e.Append(1); e.Append(4); e.Append(7);
	cout << "e = "; e.Output(); cout << endl;
	e = a.Sub(b); //求a和b的差集
	cout << "e = "; e.Output(); cout << endl;
	return 0;
}
