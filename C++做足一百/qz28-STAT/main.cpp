/*2.	ͳ����ʵ��
�Ӽ�������һ����ʵ��(�������), ���㲢�������ʵ�����ܺ͡����ֵ����Сֵ��ƽ��ֵ�ͱ�׼��(С����ʽ, ֻ��ʾ2λС��); �ڲ��������в���ĳ��ʵ��, �����ҳɹ�, ����ʾ���������е�λ��, ������ʾ������Ϣ; ������ʵ���������������Ȼ�����(С����ʽ, ֻ��ʾ2λС��)��
����: ����һ����ʵ��(�������)������p��, ����¼��ʵ���ĸ���
void Input(double *p, int &n);
���: ��������е�ȫ����ʵ��
void Output(const double *p, int n);
ͳ��: ����������ʵ�����ܺ͡����ֵ����Сֵ��ƽ��ֵ
void Stat(const double *p, int n, double &sum, double &max, double &min, double &avg);
����: ���������е�һ��ֵΪx��ʵ��, �����ҳɹ�, �򷵻���λ��(1~n), ���򷵻�0
int Find(const double *p, int n, double x);
����: ��ð�ݷ������鰴��������
void Sort(double *p, int n);
����: ������ʵ��x��y��ֵ
void Swap(double &x, double &y);
���, ��д������, ��ʾ����ͼ��ʾ�Ĳ˵�*/

#include <iostream>

using namespace std;

#include "MyMenu.h"

#include "MyStat.h"

int main()
{
	NODE *L;
	char x;
	double sum, max, min, avg, a;
	Init(L);
	do
	{
		switch(x = Menu("*********************************************\n"
					"*                ͳ����ʵ��                 *\n"
					"* ----------------------------------------- *\n"
					"* 1-���� 2-��� 3-ͳ�� 4-���� 5-���� 0-���� *\n"
					"*********************************************\n"
					"��ѡ��:",
					"012345"))
		{
		case '1':
			Append(L);
			break;
		case '2':
			List(L);
			break;
		case '3':
			Stat(L, sum, max, min, avg);
			cout << "SUM: " << sum << endl;
			cout << "MAX: " << max << endl;
			cout << "MIN: " << min << endl;
			cout << "AVG: " << avg << endl;
			break;
		case '4':
			cout << "Input the number you find:";
			cin >> a;
			cout << "POSITION: " << Find(L, a) << endl;
			break;
		case '5':
			Sort(L);
			List(L);
			break;
		case '0':
			break;
		}
	}
	while('0' !=  x);
	return 0;
}
