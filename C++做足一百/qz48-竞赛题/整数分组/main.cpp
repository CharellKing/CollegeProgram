/*5.	��������
����n(nΪż��)�����ظ���������, ����ֳɸ�����ȵ�����, ʹ���������ܺ������С��
����: ����4��������3, 9, 1, 4���������Ϊ: (3, 9)��(1, 4), ����ĺͷֱ�Ϊ12��5, ���Ϊ7; ������Ϊ: 
(1, 9)��(3, 4)ʱ, ����ĺͷֱ�Ϊ10��7, ���Ϊ3, �����С��
 	��������
ÿ�������������, ��һ��������n, �ڶ�����n������m1��m2������mn����nΪ0ʱ������
 	�������
ÿ�������������, �ֱ�����������, ÿ���������������������, �ҵ�һ��������ȵڶ��������С*/
#include <iostream>

using namespace std;

const int M = 50;

void Swap(double &x, double &y)
{
	double z = x;
	x = y;
	y = z;
}

void Sort(double *p, int n)
{
	int i, j, k;
	for(i = 0; i < n; i ++)
	{
		k = i;
		for(j = i + 1; j < n; j ++)
		{
			if(p[j] < p[k]) k = j;
		}
		Swap(p[i], p[k]);
	}
}

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
	double num, array1[M], array2[M/2], array[M/2], s1 = 0, s2 = 0;
	int i = 0, j, m, n;
	while(cin >> num, num)
	{
		if(!Exist(array, i, num)) array[i ++] = num;
	}
	Sort(array, i);
	for(j = 1, m = 0, n = 0; j <= i / 2; j ++)
	{
		if(j % 2) array1[m ++] = array[j - 1], s1 += array[j - 1], array1[m ++] = array[i - j], s1 += array[i - j];
		else array2[n ++] = array[j - 1], s2 += array[j - 1], array2[n ++] = array[i - j], s2 += array[i - j];
	}
	if(i % 2)
	{
		if(s2 > s1) array1[m ++] = array[(i - 1) % 2];
		else array2[n ++] = array[(i - 1) % 2];
	}
	Sort(array1, m);
	Sort(array2, n);
	Output(array1, m); cout << endl;
	Output(array2, m); cout << endl;
	return 0;
}
