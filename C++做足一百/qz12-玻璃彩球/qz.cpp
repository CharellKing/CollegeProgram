//5.	��������
//��10����ͬɫ�ʵĲ�������ȡ��4���ڳ�һ��, һ���ж����ֲ�ͬ�İڷ�? (��: 5040)
//int Arrange(int m, int n);	// ��: Arrange(5, 2) = 20

#include <iostream>

int Arrange(int m, int n);

using namespace std;

int main()
{
	int ballSum, pickedSum;
	cout << "Rank the color ball!\n" ;
	cout << "Please input the sum of these color ball:";
	cin >> ballSum;
	cout << "\n";
	cout << "Next take some balls to rank in a row!\n";
	cout << "Please input the sum of picked ball:";
	cin >> pickedSum;
	cout << endl;
	cout << "The sum of sort ranking the pickedball is " << Arrange(ballSum, pickedSum) << "!\n";
	return 0;
}

int Arrange(int m, int n)
{
	int k = m, arrangeSum = 1;
	while(k >= m - n + 1)
	{
		arrangeSum *= k;
		k --;
	}
	return arrangeSum;
}



 
