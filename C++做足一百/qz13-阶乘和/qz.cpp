//6.	阶乘和
//输入正整数n, 计算阶乘和: 1! + 2! + 3! + … + n!
//int SumOfFac(int n);	// SumOfFac(3) = 9, SumOfFac(9) = 153

#include <iostream>

double SumOfFac(int n);	// SumOfFac(3) = 9, SumOfFac(9) = 153

using namespace std;

int main()
{
	int max;
	cout << "Please input the max:\n";
	cin >> max;
	cout << "Output the sum of factorials:\n" << SumOfFac(max) << endl;
	return 0;
}

double SumOfFac(int max)
{
	int i = 1, k = 1; 
	double sum = 0;
	while(i <= max)
	{
		k *= i;
		sum += k;
		i ++;
	}
	return sum;
}



	
