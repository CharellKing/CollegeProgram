/*1.	�������ܺ�
����һ��������n(n > 1), ������ȫ�������ӵ��ܺ͡�
����: n = 12, ��Ȼn = 2   2   3, ��2 + 2 + 3 = 7��
 	��������
ÿ���������һ��, ֻһ������n����nΪ0ʱ������
 	�������
ÿ���������һ��, ֻһ������, �������ӵ��ܺ͡�
 	��������
����	���
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
			
