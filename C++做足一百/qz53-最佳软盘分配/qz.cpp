/*�ڳ���ȥ�ȼ�֮ǰ����ϣ�������һЩ����Ҫ���ļ����ݵ������ϡ�ÿ���հ����̵�������1.44MB��
����Ҫ���ݵ�16���ļ��Ĵ�С�ֱ�Ϊ��
46KB��55KB��62KB��87KB��108KB��114KB��137KB��164KB��
253KB��364KB��372KB��388KB��406KB��432KB��461KB��851KB��
�ٶ����޷�ʹ��ѹ������������������㹻��
��ôӦ��ν���Щ�ļ����䵽ÿһ�������ϲ���ʹʹ�õ�������Ŀ���٣�
*/

#include <iostream>

using namespace std;

#include <cstdlib>

const double a[] = {46, 55, 62, 87, 108, 114, 137, 164, 253, 364, 372, 388, 406, 432, 461, 851};

const double b = 1433.6;

const int c = 16;

bool t = false;

int method = 0;

void Fun2(int d, double f[][16], bool *g, int *h, int m, int j, int i)
{
	double sum;
	if(d < m)
	{
		if(j < h[d])
		{
			for(;i < c; i ++)
			{
				if(!g[i]) f[d][j] = a[i], g[i] = true, 
				Fun2(d, f, g, h, m, ++j, ++i), j --, g[i - 1] = false;
			}
			if(i == c && j < h[d]) return; 
		}
		else
		{
			f[d][j] = 0;
			sum = 0;
			for(i = 0; f[d][i]; i ++) sum += f[d][i];
			if(sum <= b) Fun2(++d, f, g, h, m, j = 0, i = 0);
			else return ;
		}
	}
	else
	{
		/*for(i = 0; i < m; i ++)
		{
			cout << "��" << i + 1 << "��: ";
			for(j = 0; f[i][j]; j ++)
			{
				 cout << f[i][j] << ' ';
			}
			cout << endl;
		}*/
		t = true;
		method ++;
		//exit(1);
	}
}

void Fun1(int d, double f[][16], bool *g, int *h, int m, int i)
{
	int j, k;
	if(d - 1 <= 0)
	{
		h[0] = c;
		for(i = 1; i < m; i ++)
		{
			h[0] -= h[i];
		}
		if(h[0] >= h[1]) Fun2(0, f, g, h, m, j = 0, k = 0);
		else return;
	}
	else
	{
		for(; i < c - m + 1; i ++)
		{
			h[d - 1] = i;
			Fun1(d - 1, f, g, h, m, i);
		}
	}

}

int main()
{
	int d = 3, n;
	while(1)
	{
		int i, *h;
		bool *g;
		double f[16][16]; 
		h = new int[d];
		g = new bool[c];
		for(i = 0; i < c; i ++) g[i] = false;
		Fun1(d, f, g, h, d, n = 1);
		if(t)
		{
			cout << "ʹ����С������Ϊ" << d << endl;
			cout << "methods: " << method << endl;
			break;
		}
		d ++;
	}
	return 0;
}




