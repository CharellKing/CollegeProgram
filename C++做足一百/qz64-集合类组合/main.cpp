//1.	集合类(一):
//设计实数集合类(MYSET), 包含两个数据成员, 一个是指向动态实数数组的指针elements, 
//一个是基合的基数cardinal, 一个是数组的尺寸size。请为该类设计构造函数、析构函数, 
//以及公有成员函数Cardinal(集合基数)、IsEmpty(判断空集)、Append(添加元素)、Remove(删除元素)、
//Clear(清空集合)、Find(查找元素)、Exist(判断元素)、Get(读取元素)、Input(输入集合)
//和Output(输出集合)等, 完成以下功能:

#include <iostream>

using namespace std;

#include "ARRAY_MYSET.H"

#include "LINKLIST_MYSET.H"

void Test(MYSET &x)
{
	x.Output(); cout << endl;
}

int main()
{
	ARRAY_MYSET a;
	LINKLIST_MYSET b;
	ARRAY_MYSET c;
	LINKLIST_MYSET d;
	MYSET *e;
	a.Append(2.5); a.Append(3.8); a.Append(4.6);
	a.Output(); cout << endl;
	b.Append(2.4); b.Append(3.8); b.Append(4.9);
	b.Output(); cout << endl;
	e = &a;
	a.Output(); cout << endl;
	b.Add(a, c);
	c.Output(); cout << endl;
	b.Mul(a, c);
	c.Output(); cout << endl;
	b.Sub(a, d);
	d.Output(); cout << endl;
	Test(a);
	return 0;
}


