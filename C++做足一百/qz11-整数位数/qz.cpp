//4.	整数的位数
//求整数x的位数。
//int Len(int x); // 例: Len(25173) = 5, Len(450) = 3, Len(0) = 1

#include <iostream>

typedef int style;

style Len(style integer);

style Fac(style integer);

using namespace std;

int main()
{
	style integer;
	cout << "Please input a integer:\n";
	cin >> integer;
	cout << "the sum of the number's digit is" << Len(integer) <<"!\n" << endl;
	return 0;
}

style Len(style integer)
{
	style digitSum = 0, k = 1;
	if(integer == 0) digitSum = 1;
	else
	{
		while(k <= Fac(integer)) 
		{
			k *= 10;
			digitSum ++;
		}
	}
	return digitSum;
}
	
style Fac(style integer)
{
	if(integer < 0) integer = - integer;
	return integer;
}

		



