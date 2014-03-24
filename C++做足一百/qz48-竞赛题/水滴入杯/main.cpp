/*3.	水滴入杯
有一只空水杯, 水滴不断地滴入杯中, 假设水杯容量为120滴水。当杯中水量达到或超过2/3后, 每滴入一滴水, 
杯中就会有1/120的水被溅出。试问, 当杯中水量累积到n(80   n < 120)滴水时, 需要滴多少滴水?
 	输入数据
每个输入包括一行, 只一个整数n。当n为0时结束。
 	输出数据
每个输出包括一行, 只一个整数, 即滴入的水滴总数。
 	测试样例*/

#include <iostream>

using namespace std;

int Drops(int drops)
{
	int i;
	double volume;
	if(drops <= 80) i = drops;
	else
	{
		volume = 80;
		for(i = 80; volume <= drops; i ++)
		{
			volume = volume * 119 / 120 + 1;
		}
	}
	return i;
}

int main()
{
	int i, j;
	while(cin >> i, i)
	{
		j = Drops(i);
		cout << j << endl;
	}
	return 0;
}



		
	
