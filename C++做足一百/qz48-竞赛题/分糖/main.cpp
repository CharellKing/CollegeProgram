/*6.	����
��n(n<60)���Ƿָ�k(1   k < 20)����, ÿ�˷ֵ�����������1�š�����m (1   m < 10)��, һ���ж����ַַ�?
����: ��n = 3, k = 2, m = 2ʱ, ֻ��1�ַַ�: (1, 2)������(1, 2)��(2, 1)����Ϊ��ͬһ�ַַ���
����: ��n = 6, k = 3, m = 3ʱ, ��2�ַַ�: (1, 2, 3), (2, 2, 2)��
 	��������
ÿ�������������, ��һ��������n, �ڶ���������k��m����nΪ0ʱ������
 	�������
ÿ���������һ��, ֻһ������, �����Ƿ�����������*/

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


