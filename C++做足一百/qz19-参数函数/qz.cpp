//8.	参数方程
//编写星形线函数:
//void Star(double *x, double *y, double t);
 
#include <iostream>

#include <math.h>

void Star(double &x, double &y, double t);

using namespace std;

int main()
{
	double t, value1, value2;
	cout << "Please input the value of 't':\n";
	cin >> t;
	Star(value1, value2, t);
	cout << "The value of 'x' is " << value1 << " !\n";
	cout << "The value of 'y' is " << value2 << " !\n";
	return 0;
}

void Star(double &x, double &y, double t)
{
	double t1, t2;
	t1 = cos(t);
	t2 = sin(t);
	x = t1 * t1 * t1;
	y = t2 * t2 * t2;
}



