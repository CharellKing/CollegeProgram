//1.	������(һ):
//���ʵ��������(MYSET), �����������ݳ�Ա, һ����ָ��̬ʵ�������ָ��elements, 
//һ���ǻ��ϵĻ���cardinal, һ��������ĳߴ�size����Ϊ������ƹ��캯������������, 
//�Լ����г�Ա����Cardinal(���ϻ���)��IsEmpty(�жϿռ�)��Append(���Ԫ��)��Remove(ɾ��Ԫ��)��
//Clear(��ռ���)��Find(����Ԫ��)��Exist(�ж�Ԫ��)��Get(��ȡԪ��)��Input(���뼯��)
//��Output(�������)��, ������¹���:

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


