/*8.	�������
�ٶ�ĳ������n����ֵ�Ļ���, ���ǵĽ��Ӵ�С�ֱ�Ϊc1��c2��������cn, ����һ�����a, �������ж�������Ϸ���?
���蹲��3��ֵ�Ļ���, �ֱ���: 4, 2, 1, ���ڽ��7����������6����Ϸ���: 
4+2+1, 4+1+1+1, 2+2+2+1, 2+2+1+1+1, 2+1+1+1+1+1, 1+1+1+1+1+1+1
ע: 4+2+1��1+4+2��1+2+4����Ϊ����ͬ�����, ��Ϊ1�֡�
 	��������
ÿ�������������, ��һ��������n, �ڶ�����n������c1��c2������cn, �������ǽ��a����nΪ0ʱ������
 	�������
ÿ���������һ��, ֻһ������, ����Ϸ�����������
 	��������
����	���
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
