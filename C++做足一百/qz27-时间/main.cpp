//1.	ʱ��
//���ʱ��ṹ����TIME, ������������Ա: hour��minute��second, �ֱ��ʾʱ���ֺ��롣�������ĺ���:
//void Input (TIME &x); // ����ʱ������
//void Output (const TIME &x); // ���ʱ������
//TIME Add (const TIME &x, int s); // ��ʱ��x��s�����õ�ʱ��(ע: sΪ��������)
//TIME Sub (const TIME &x, int s); // ��ʱ��x��s�����õ�ʱ��(ע: sΪ��������)
//int Sub(const TIME &x, const TIME &y); // ������ʱ��x��y֮�����������
//bool IsValid(int hout, int minute, int second); // �ж�hour, minute, second�Ƿ�Ϊ�Ϸ�ʱ��
//void Set(int hour, int minute, int second); // ����ʱ��
//void Get(int &hour, int &minute, int &second); // ��ȡʱ��

#include <iostream>

#include <conio.h>

#include "MyTime.h"

using namespace std;

int main()
{
	TIME time1, time2;
	int s;
	cout << "Please input the time in the way(23:45:56)\n";
	Input (time1); // ����ʱ������
	Output (time1); // ���ʱ������
	cout << "Please input the seconds you add:\n";
	cin >> s;
	Output(Add (time1, s)); // ��ʱ��x��s�����õ�ʱ��(ע: sΪ��������)
	Output(Sub (time1, s)); // ��ʱ��x��s�����õ�ʱ��(ע: sΪ��������)
	Input (time2); // ����ʱ������
	Output (time2); // ���ʱ������
	cout << "deltSecond:" << Sub(time1, time2) << endl; // ������ʱ��x��y֮�����������
	Set(int hour, int minute, int second); // ����ʱ��

	getch();
	return 0;
}
	
