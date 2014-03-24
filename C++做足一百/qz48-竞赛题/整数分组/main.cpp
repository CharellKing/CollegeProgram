/*5.	整数分组
输入n(n为偶数)个不重复的正整数, 将其分成个数相等的两组, 使两组数的总和相差最小。
例如: 输入4个正整数3, 9, 1, 4。将其分组为: (3, 9)和(1, 4), 两组的和分别为12和5, 差额为7; 而分组为: 
(1, 9)和(3, 4)时, 两组的和分别为10和7, 差额为3, 相差最小。
 	输入数据
每个输入包括两行, 第一行是整数n, 第二行是n个整数m1、m2、…、mn。当n为0时结束。
 	输出数据
每个输出包括两行, 分别是两组整数, 每组整数都按升序排序输出, 且第一组的首数比第二组的首数小*/
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
