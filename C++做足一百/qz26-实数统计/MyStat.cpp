#include <iostream>

#include <iomanip>

#include "MyStat.h"

using namespace std;

void Input(double *p, int &n)
{
	int i = 0;
	double number;
	while(cin >> number, number) /*Round(number, 2), */p[i++] = number;
	n = i;
}

void Output(const double *p, int n)
{
	int i;
	for(i = 0; i < n; i ++) cout << setprecision(2) << fixed << setw(8) << right << p[i] << endl;
}

void  Round(double &anumber, char afterpoint)
{
	int i = 0;
	for(; i < afterpoint; anumber *= 10, i ++);
	anumber += 0.5;
	anumber = ((int)anumber) / 100.0;
}

void Stat(const double *p, int n, double &sum, double &max, double &min, double &avg)
{
	int i = 0;
	max = 1e-6, min = 1e6, sum = 0;
	for(; i < n; i ++)
	{
		sum += p[i];
		if(p[i] < min) min = p[i];
		if(p[i] > max) max = p[i];
	}
	avg = sum / n;
}

int Find(const double *p, int n, double x)
{
	int i;
	for(i = 0; i < n && p[i] != x; i ++);
	if(i == n) return 0;
	return ++i;
}

void Swap(double &x, double &y)
{
	double number = x;
	x = y;
	y = number;
}

void Sort(double *p, int n)
{
	int i, j, k;
	for(i = 0; i < n - 1; i ++)
	{
		j = k = i;
		for(j ++; j < n; j ++)
		{
			if(p[k] > p[j]) k = j;
		}
		Swap(p[k], p[i]);
	}
}





