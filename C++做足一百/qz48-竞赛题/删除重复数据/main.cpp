/*2.	删除重复数据
从键盘输入n个整数a1, a2, ..., an, 删去其中重复的数据, 然后输出。
例如: 输入10个整数: 1, 5, 3, 2, 1, 3, 8, 4, 1, 6, 输出: 1, 5, 3, 2, 8, 4, 6。
 	输入数据
每个输入包括两行, 第一行是整数n, 第二行是n个整数a1, a2, ..., an。当n为0时结束。
 	输出数据
每个输出包括一行, 即删除重复数据后的若干整数。
 	测试样例
输入	输出
3
1 2 1
5
1 2 1 2 1
10
1 5 3 2 1 3 8 4 1 6
0	1 2
1 2
1 5 3 2 8 4 6
*/

#include <iostream>

using namespace std;

const int M = 100;

bool Exist(double *array, int n, double real)
{
	for(-- n; n >= 0; n --)
	{
		if(real == array[n]) return true;
	}
	return false;
}

void Output(double *array, int n)
{
	for(n --; n >= 0; n --)
	{
		cout << ' ' << array[n];
	}
}

int main()
{
	double num, array[M];
	int i = 0;
	while(cin >> num, num)
	{
		if(!Exist(array, i, num)) array[i ++] = num;
	}
	Output(array, i); cout << endl;
	return 0;
}

