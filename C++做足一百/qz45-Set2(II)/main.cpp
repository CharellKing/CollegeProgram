//1.	������(һ):
//���ʵ��������(MYSET), �����������ݳ�Ա, һ����ָ��̬ʵ�������ָ��elements, 
//һ���ǻ��ϵĻ���cardinal, һ��������ĳߴ�size����Ϊ������ƹ��캯������������, 
//�Լ����г�Ա����Cardinal(���ϻ���)��IsEmpty(�жϿռ�)��Append(���Ԫ��)��Remove(ɾ��Ԫ��)��
//Clear(��ռ���)��Find(����Ԫ��)��Exist(�ж�Ԫ��)��Get(��ȡԪ��)��Input(���뼯��)
//��Output(�������)��, ������¹���:

#include <iostream>

using namespace std;

#include "MYSET.H"

void Test(MYSET &x)
{
	x.Output(); cout << endl;
}

int main()
{
	MYSET a;
	a.Append(2.5); a.Append(3.8); a.Append(4.6);
	cout << endl;
	Test(a);
	return 0;
}