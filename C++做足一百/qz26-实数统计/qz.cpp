#include <iostream>

//#include <conio.h>

#include "MyStat.h"

using namespace std;

void Choose(double *array, int &num, int n);

int main()
{
	double array[M];
	int num, n;
	do
	{
		cout << "*********************************************\n"
				"*                ͳ����ʵ��                 *\n"
				"* ----------------------------------------- *\n"
				"* 1-���� 2-��� 3-ͳ�� 4-���� 5-���� 0-���� *\n"
				"*********************************************\n"
				"��ѡ��:";
		cin >> n;
		Choose(array, num ,n);
	}
	while(n);
	return 0;
}

void Choose(double *array, int &num, int n)
{
	double sum, max, min, avg, x;
	switch (n)
	{
		case 1:
		cout << "Please input a array of number:(end up with 0)\n";
		Input(array, num);
		break;
		case 2:
		Output(array, num);
		break;
		case 3:
		Stat(array, num, sum, max, min, avg);
		cout << "sum: " << sum << endl;
		cout << "max: " << max << endl;
		cout << "min: " << min << endl;
		cout << "avg: " << avg << endl;
		break;
		case 4:
		cout << "Please input the number you find:\n";
		cin >> x;
		cout << "Position: " << Find(array, num, x) << endl;
		break;
		case 5:
		Sort(array, num);
		Output(array, num);
		break;
	}
}




