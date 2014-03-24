#include <iostream>

using namespace std;

#include "RESISTANCE.H"

#include "BOARD.H"

int main()
{
	/*const*/BOARD a(3, 4, 5); // ������������ֱ�Ϊ3 ��4 ��5 ��·��
	cout << a.Resistance1() << endl;	// ��ȡ��1���������ֵ
	cout << a.Resistance2() << endl;	// ��ȡ��2���������ֵ
	cout << a.Resistance3() << endl;	// ��ȡ��3���������ֵ
	cout << a.Current1() << endl;	// ��ȡ��1�������ϵĵ���
	cout << a.Current2() << endl;	// ��ȡ��2�������ϵĵ���
	cout << a.Current3() << endl;	// ��ȡ��3�������ϵĵ���
	cout << a.Voltage1() << endl;	// ��ȡ��1�������ϵĵ�ѹ
	cout << a.Voltage2() << endl;	// ��ȡ��1�������ϵĵ�ѹ
	cout << a.Voltage3() << endl;	// ��ȡ��1�������ϵĵ�ѹ
	cout << a.Resistance() << endl;	// ��ȡ�ܵ���
	cout << a.Current() << endl;	// ��ȡ�ܵ���
	cout << a.Voltage() << endl;	// ��ȡ�ܵ�ѹ

	a.Current(1.5);	// ����·�����1.5A����
	cout << a.Resistance1() << endl;	// ��ȡ��1���������ֵ
	cout << a.Resistance2() << endl;	// ��ȡ��2���������ֵ
	cout << a.Resistance3() << endl;	// ��ȡ��3���������ֵ
	cout << a.Current1() << endl;	// ��ȡ��1�������ϵĵ���
	cout << a.Current2() << endl;	// ��ȡ��2�������ϵĵ���
	cout << a.Current3() << endl;	// ��ȡ��3�������ϵĵ���
	cout << a.Voltage1() << endl;	// ��ȡ��1�������ϵĵ�ѹ
	cout << a.Voltage2() << endl;	// ��ȡ��1�������ϵĵ�ѹ
	cout << a.Voltage3() << endl;	// ��ȡ��1�������ϵĵ�ѹ
	cout << a.Resistance() << endl;	// ��ȡ�ܵ���
	cout << a.Current() << endl;	// ��ȡ�ܵ���
	cout << a.Voltage() << endl;	// ��ȡ�ܵ�ѹ

	a.Voltage(3.5);	// ����·�����3.5V��ѹ
	cout << a.Resistance1() << endl;	// ��ȡ��1���������ֵ
	cout << a.Resistance2() << endl;	// ��ȡ��2���������ֵ
	cout << a.Resistance3() << endl;	// ��ȡ��3���������ֵ
	cout << a.Current1() << endl;	// ��ȡ��1�������ϵĵ���
	cout << a.Current2() << endl;	// ��ȡ��2�������ϵĵ���
	cout << a.Current3() << endl;	// ��ȡ��3�������ϵĵ���
	cout << a.Voltage1() << endl;	// ��ȡ��1�������ϵĵ�ѹ
	cout << a.Voltage2() << endl;	// ��ȡ��1�������ϵĵ�ѹ
	cout << a.Voltage3() << endl;	// ��ȡ��1�������ϵĵ�ѹ
	cout << a.Resistance() << endl;	// ��ȡ�ܵ���
	cout << a.Current() << endl;	// ��ȡ�ܵ���
	cout << a.Voltage() << endl;	// ��ȡ�ܵ�ѹ
	return 0;
}	

