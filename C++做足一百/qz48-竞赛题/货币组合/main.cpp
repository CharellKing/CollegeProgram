/*8.	货币组合
假定某国共有n种面值的货币, 它们的金额从大到小分别为c1、c2、……、cn, 给定一个金额a, 它可以有多少种组合方法?
假设共有3面值的货币, 分别是: 4, 2, 1, 对于金额7可以有以下6种组合方法: 
4+2+1, 4+1+1+1, 2+2+2+1, 2+2+1+1+1, 2+1+1+1+1+1, 1+1+1+1+1+1+1
注: 4+2+1、1+4+2和1+2+4被认为是相同的组合, 计为1种。
 	输入数据
每个输入包括三行, 第一行是整数n, 第二行是n个整数c1、c2、…、cn, 第三行是金额a。当n为0时结束。
 	输出数据
每个输出包括一行, 只一个整数, 即组合方法的数量。
 	测试样例
输入	输出
2
3 1
5
3
4 2 1
8
0	2
9*/

#include <iostream>

using namespace std;

void MoneyExchange(const int *p, int a_piece_of_money, int &methods, int i, int n);

int main()
{
	int *currency_denomination, a_piece_of_money, methods, n;
	while(cin >> n, n)
	{
		methods = 0;
		currency_denomination = new int[n];
		for(int i = 0; i < n; i ++)
		{
			cin >> currency_denomination[i];
		}
		cin >> a_piece_of_money;
		i = 0;
		MoneyExchange(currency_denomination, a_piece_of_money, methods, i, n);
		cout << "METHODS:" << methods << endl;
	}	
	return 0;
}

void MoneyExchange(const int *p, int a_piece_of_money, int &methods, int i, int n)
{
	int m;
	if(a_piece_of_money == 0) methods ++;
	else
	{
		for(; i < n; i ++)
		{
			m = a_piece_of_money - p[i];
			if(m >= 0) MoneyExchange(p, m, methods, i, n);
		}
	}
}
