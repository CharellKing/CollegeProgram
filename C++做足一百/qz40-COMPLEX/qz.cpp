//2.	������(MYCOMPLEX)
//��Ƹ�����, ����������˽�����ݳ�Ա: real��imaginary, �ֱ��ʾʵ�����鲿ϵ����
//��Ϊ������ƹ��г�Ա����, ������»�������: 
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




