//No pass:
//  1 2 3 4
//	0 0 5 6
//	8 9 1 1
#include <iostream>

#include <iomanip>

#include <cstdlib>

using namespace std;

typedef unsigned char car;

void InputReal(double *p, car n);

void OutputMatrix (const double *p, car n);

void StairMatrix(double *equationGroup, car equationNum, car rooms);

void SolveEquationGroup(const double *equationGroup, car equationNum, car rooms, double *roots);

void Exchange(double *equationGroup, car line, car j, car i);

void Swap(double &x, double &y);

int main()
{
	car rooms, i;
	unsigned short int equationNum;
	cout << "Please input the number of eqution's number:";
	cin  >> equationNum;
	rooms = equationNum * (equationNum + 1);
	double *equationGroup = new double [rooms];
	double *roots = new double [equationNum];
	cout << "Please input the coefficients and constants:\n";
	InputReal(equationGroup, rooms);
	OutputMatrix(equationGroup, equationNum);
	StairMatrix(equationGroup, equationNum, rooms);
	SolveEquationGroup(equationGroup, equationNum, rooms, roots);
	for(i = 0; i < equationNum;) cout << "root " << (int) i << ":  " << roots[i ++] << endl; 
	delete []equationGroup;
	delete []roots;
	return 0;
}

void InputReal(double *p, car n)
{
	car i = 0;
	for(; i < n; i ++)
	{
		cin >> p[i];
	}
}

void OutputMatrix (const double *p, car n)
{
	car k = 0, i = 0;
	for(; k < n; i ++)
	{
		cout << setw(10) << setprecision(10) << p[i] << " ";
		if(i % (n + 1) == n) k ++, cout << endl;
	}
	cout << setprecision(10) << endl;
}

void StairMatrix(double *equationGroup, car equationNum, car rooms)
{
	bool b;
	car line = equationNum + 1, i, j, row = equationNum, k, m, n;
	double mutiple;
	for(i = 1; i < row; i ++)
	{
		b = false;
		k = (i - 1) * (line + 1);
		if(!equationGroup[k])
		{
			for(j = i + 1; j <= row && !b; j ++)
			{
				if(equationGroup[(j - 1) * line + i - 1])
				{
					b = true;
				}
			}
			if(b) Exchange(equationGroup, line, --j, i);
			else
			{
				cout << "此方程有无穷解!" << endl;
				exit(1);
			}
		}
		j = k;
		for(j += line; j < rooms; j += line)
		{
			if(equationGroup[j])
			{
				m = j, n = k;
				mutiple = equationGroup[m] / equationGroup[n];
				m -= (i - 1), n -= (i - 1);
				for(k = 0; k < line; k ++) equationGroup[m ++] -= (equationGroup[n ++] * mutiple);
			}
		}
	}
}

		
void SolveEquationGroup(const double *equationGroup, car equationNum, car rooms, double *roots)
{
	car i, n, j = rooms - 1, line = equationNum + 1, a;
	double sum, s;
	for(i = 1, a = equationNum; i <= equationNum; i ++)
	{
		sum = 0;
		for(n = 1; n < i; sum += (equationGroup[j - n] * roots[equationNum - n]), n ++);
		s = equationGroup[j] - sum;
		if(equationGroup[j - n]) roots[--a] = s / equationGroup[j - n];
		else if(s) cout << "此方程无解!\n", exit(1);
		else cout << "此方程有无穷解!\n" << endl, exit(1);
		j -= line;
	}
}

void Exchange(double *equationGroup, car line, car j, car i)
{
	car m, n, k;
	m = (j - 1) * line, n = (i - 1) * line;
	for(k = 0; k < line; k ++)
	{
		Swap(equationGroup[m ++], equationGroup[n ++]);
	}
}

void Swap(double &x, double &y)
{
	double z = x;
	x = y;
	y = z;
}