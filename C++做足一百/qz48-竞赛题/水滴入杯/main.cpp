/*3.	ˮ���뱭
��һֻ��ˮ��, ˮ�β��ϵص��뱭��, ����ˮ������Ϊ120��ˮ��������ˮ���ﵽ�򳬹�2/3��, ÿ����һ��ˮ, 
���оͻ���1/120��ˮ������������, ������ˮ���ۻ���n(80   n < 120)��ˮʱ, ��Ҫ�ζ��ٵ�ˮ?
 	��������
ÿ���������һ��, ֻһ������n����nΪ0ʱ������
 	�������
ÿ���������һ��, ֻһ������, �������ˮ��������
 	��������*/

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



		
	
