//��ʵ��3�е�ʱ��ṹ�Ľ�Ϊʱ����, ����������˽�����ݳ�Ա: hour��minute��second, �ֱ��ʾʱ���ֺ��롣
//Ȼ�����Input(����)��Output(���)��Set(����)��Get(��ȡ)��Hour(ʱ��д)��Minute(�ֶ�д)��Second(���д)�ȹ��г�Ա����, 
//������»�������: 
#include <iostream>

using namespace std;

#include "MYTIME.H"

int main()
{
	MYTIME a;
	a.Set(8, 10, 15);
	cout << a.Hour() << endl;
	cout << a.Minute() << endl;
	cout << a.Second() << endl;
	a.Hour(21);   // ������ʱ
	cout << "a = "; a.Output(); cout << endl;
	a.Minute(40); // �����÷�
	cout << "a = "; a.Output(); cout << endl;
	a.Second(45); // ��������
	cout << "a = "; a.Output(); cout << endl;
	a.Hour(87);    // ��������(��������)
	a.Minute(-45); // ��������(��������)
	a.Second(100); // ��������(��������)
	cout << "a = "; a.Output(); cout << endl;
	return 0;
}
