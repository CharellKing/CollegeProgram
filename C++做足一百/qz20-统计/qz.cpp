//1.	ͳ��(һ)
//��д����, �Ӽ�������һ����ʵ��(�������), ��ʵ���������ܺ͡����ֵ����Сֵ��ƽ��ֵ��
//void Stat(int *num, double *sum, double *max, double *min, double *avg);

#include <iostream>

#include "MyStat.h"

int main()
{
	STAT Fun;
	double array[M];
	cout << "Please input a group of real numbers:(end with 0)\n";
	Fun.Input(array);
	cout << "The amount of the group of real numbers is " << Fun.GetAmount() << "!\n" << endl;
	Fun.Sum(array);
	cout << "The sum of the group of real number is " << Fun.GetSum() << " !\n" << endl;
	Fun.SpecialValue(array);
	cout << "The max of the group of real number is " << Fun.GetMax() << " !\n" << endl;
	cout << "The min of the group of real number is " << Fun.GetMin() << " !\n" << endl;
	Fun.Average(array);
	cout << "The average of the group of real number is " << Fun.GetAverage() << " !\n" << endl;
	return 0;
}




