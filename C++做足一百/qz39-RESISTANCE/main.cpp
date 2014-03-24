#include <iostream>

using namespace std;

#include "RESISTANCE.H"

void Test1();

void Test2();

int main()
{
	Test1();
	Test2();
	return 0;
}

void Test1()
{
	RESISTANCE a; // ������ֵΪ1 �ĵ���, �������͵�ѹ��ʼ��0A��0V
	a.Current(1); // ��������Ϊ1A
	cout << "��ֵ: " << a.Resistance() << endl;
	cout << "����: " << a.Current() << endl;
	cout << "��ѹ: " << a.Voltage() << endl;
}

void Test2()
{
	RESISTANCE b(2.5); // ������ֵΪ2.5 �ĵ���, �������͵�ѹ��ʼ��0A��0V
	b.Voltage(3.5);    // ��ѹ����Ϊ3.5V
	cout << "��ֵ: " << b.Resistance() << endl;
	cout << "����: " << b.Current() << endl;
	cout << "��ѹ: " << b.Voltage() << endl;
}
