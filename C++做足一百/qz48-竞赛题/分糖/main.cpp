/*6.	分糖
将n(n<60)颗糖分给k(1   k < 20)个人, 每人分到的数量至少1颗、至多m (1   m < 10)颗, 一共有多少种分法?
例如: 当n = 3, k = 2, m = 2时, 只有1种分法: (1, 2)。其中(1, 2)和(2, 1)被认为是同一种分法。
再如: 当n = 6, k = 3, m = 3时, 有2种分法: (1, 2, 3), (2, 2, 2)。
 	输入数据
每个输入包括两行, 第一行是整数n, 第二行是整数k和m。当n为0时结束。
 	输出数据
每个输出包括一行, 只一个整数, 即分糖方法的种数。*/

#include <iostream>

using namespace std;

void PickCandy(int candy_num, int child_num, int pick_max_num, int &methods, int start);

int main()
{
	int methods, candy_num, pick_max_num, child_num, start;
	while(cin >> candy_num, candy_num)
	{
		start = 0;
		methods = 0;
		cin >> child_num >> pick_max_num;
		PickCandy(candy_num - child_num, child_num, pick_max_num, methods, start);
		cout << "METHOD:" << methods << endl;
	}
	return 0;
}

void PickCandy(int candy_num, int child_num, int pick_max_num, int &methods, int start)
{
	int remain_candy_num, remain_child_num;
	if(child_num == 0)
	{
		if(candy_num == 0) methods ++;
	}
	else
	{
		for(; start < pick_max_num; start ++)
		{
			remain_child_num = child_num - 1;
			remain_candy_num = candy_num - start;
			if(remain_candy_num >= 0)
			PickCandy(remain_candy_num, remain_child_num, pick_max_num, methods, start);
		}
	}
}


