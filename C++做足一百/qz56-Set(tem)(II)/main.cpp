//1.	������(һ):
//���ʵ��������(MYSET), �����������ݳ�Ա, һ����ָ��̬ʵ�������ָ��elements, 
//һ���ǻ��ϵĻ���cardinal, һ��������ĳߴ�size����Ϊ������ƹ��캯������������, 
//�Լ����г�Ա����Cardinal(���ϻ���)��IsEmpty(�жϿռ�)��Append(���Ԫ��)��Remove(ɾ��Ԫ��)��
//Clear(��ռ���)��Find(����Ԫ��)��Exist(�ж�Ԫ��)��Get(��ȡԪ��)��Input(���뼯��)
//��Output(�������)��, ������¹���:

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
	c = a.Add(b); // ��a��b�Ĳ���
	cout << "c = "; c.Output(); cout << endl;

	d.Append(5); d.Append(10);
	cout << "d = "; d.Output(); cout << endl;
	d = a.Mul(b); //��a��b�Ľ���
	cout << "d = "; d.Output(); cout << endl;

	e.Append(1); e.Append(4); e.Append(7);
	cout << "e = "; e.Output(); cout << endl;
	e = a.Sub(b); //��a��b�Ĳ
	cout << "e = "; e.Output(); cout << endl;
	return 0;
}
