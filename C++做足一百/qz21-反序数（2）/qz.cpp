//4.	反序数
//编写函数求反序数。
//int RevNum(int n); // 例: Reverse(1234) = 4321;
//提示: 首先将累加器s清零; 然后将累加器s乘以10, 再加上n的个位得4, 将n除以10变为123; 
//再将累加器乘以10加上取n的个位3得43, 将n除以10变为12; …, 如此继续下去, 当n变为零时, s变为4321。
//利用上面的函数来判断回文数(正看反看都一样的数)。
//int IsPalNum(int n); // 例: IsPalNum(159743) = 0, IsPalNum(1258521) = 1

#include <iostream>

using namespace std;

#define M 50

void Input(char *p, int *m); 

int RevNum(const char *p, int n);

int main()
{
	char array[M];
	int n;
	cout << "Please input the integer:\n";
	Input(array, &n);
	cout << "The reverse number is " << RevNum(array, n) << " !\n";
	return 0;
}

void Input(char *p, int *m)
{
	int i = 1;
	do
	{
		cin.get(p[i]);
		i ++;
	}
	while(isdigit(p[i - 1]));
	*m = i - 2;
}

int RevNum(const char *p, int n)
{
	int i = 1, reversednumber = 0;
	double k = 0.1;
	for(; i <= n; i ++)
	{
		k *= 10;
		reversednumber += (p[i] - '0') * (int)k;
	}
	return reversednumber;
}



