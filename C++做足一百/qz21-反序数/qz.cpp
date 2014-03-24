//4.	反序数
//编写函数求反序数。
//int RevNum(int n); // 例: Reverse(1234) = 4321;
//提示: 首先将累加器s清零; 然后将累加器s乘以10, 再加上n的个位得4, 将n除以10变为123; 
//再将累加器乘以10加上取n的个位3得43, 将n除以10变为12; …, 如此继续下去, 当n变为零时, s变为4321。
//利用上面的函数来判断回文数(正看反看都一样的数)。
//int IsPalNum(int n); // 例: IsPalNum(159743) = 0, IsPalNum(1258521) = 1

#include <iostream>

using namespace std;

int RevNum(int n);


int main()
{
	int integer;
	cout << "Please input a integer:\n";
	cin >> integer;
	cout << "The reverse number is " << RevNum(integer) << " !\n";
	return 0;
}

int RevNum(int n)
{
	int k = 1, z, a, reverseNumber = 0;
	while(k <= n)
	{
		k *= 10;
	}
	k /= 10;
	z = k * 10;
	while(z >= 1)
	{
		z /= 10;
		a = n % 10;
		reverseNumber += a * z;
		n /= 10;
	}
	return reverseNumber;
}
		



