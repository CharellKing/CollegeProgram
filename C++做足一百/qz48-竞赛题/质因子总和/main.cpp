/*1.	质因子总和
给定一个正整数n(n > 1), 计算其全部质因子的总和。
例如: n = 12, 显然n = 2   2   3, 而2 + 2 + 3 = 7。
 	输入数据
每个输入包括一行, 只一个整数n。当n为0时结束。
 	输出数据
每个输出包括一行, 只一个整数, 即质因子的总和。
 	测试样例
输入	输出
12
15
0	7
8*/

#include <iostream>

using namespace std;

bool IsPrime(int num)
{
	int i;
	for(i = 2; i < num; i ++)
	{
		if(0 == num % i) return false;
	}
	return true;
}

int main()
{
	int integer, s, i;
	while(cin >> integer, integer)
	{
		s = 0;
		while(integer > 1)
		{
			for(i = 2; i <= integer; i ++) if(0 == integer % i && IsPrime(i)) s += i, integer /= i;
		}
		cout << s << endl;
	}
	return 0;
}
			
