//1.	�����ֵ����Сֵ(һ)
//����������x��y�����ֵ����Сֵ��
//���ֵ����: int Max(int x, int y);	// ��: Max(3, 5) = 5
//��Сֵ����: int Min(int x, int y);	// ��: Min(3, 5) = 3`

#include <iostream>

#define  style int //typedef int style;

#include <stdlib.h>

#define Max(x, y) (x > y ? x : y)

#define Min(x, y) (x < y ? x : y)

using namespace std;

int main()
{
	style number1, number2, max, min;
	cout << "Compare two integers!\n" << endl;
	cout << "Please input number1:\n";
	cin >> number1;
	cout << endl;
	cout << "please input number2:\n";
	cin >> number2;
	cout << endl;
	if(number1 == number2)
	{
		cout <<"The two numbers are equal, no max, no min!\n";
		exit (1);
	}
	max = Max(number1, number2);
	min = Min(number1, number2);
	cout << "The max is " << max << "\n" << endl;
	cout << "The min is " << min << "\n" << endl;
	return 0;
}