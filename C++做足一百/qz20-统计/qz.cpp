//1.	统计(一)
//编写函数, 从键盘输入一组正实数(以零结束), 求实数个数、总和、最大值、最小值和平均值。
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




