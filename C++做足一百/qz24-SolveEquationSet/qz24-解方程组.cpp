#include <iostream>

#include <cstdlib>

using namespace std;

const int M = 500;

typedef char car;

void InputReal(double *array, int k);

void BuildMatrix(double *array1, double *array2, car num, car diceRow, car k);

double GetDenominator(const double *array, car num);

void ZeroUndertriangle(double *array, car num);



int main()
{
	double array1[M], array2[M], a, b;
	car k, diceRow, k1;
	int num;
	cout << "Please input the number of equation:\n";
	cin >> num;
	k = num * (num + 1);
	k1 = k - num;
	cout << "Please input all the Coefficients and constants:\n";
	InputReal(array1, k);
	BuildMatrix(array1, array2, num, num + 1, k);
	ZeroUndertriangle(array2, num);
	a = GetDenominator(array2, num);
	if(!a)
	{
		cout << "NO ROOT!\n";
		exit(1);
	}
	cout << "a = " << a << endl;
	for(diceRow = 1; diceRow <= num; diceRow ++)
	{
		BuildMatrix(array1, array2, num, diceRow, k);
		ZeroUndertriangle(array2, num);
		b = GetDenominator(array2, num);
		cout << "Root" << diceRow << ":" << b / a << endl;
	}
	return 0;
}

void InputReal(double *array, int k)
{
	car c;
	for(c = 0; c < k; c ++)
	{
		cin >> array[c];
	}
}

void BuildMatrix(double *array1, double *array2, car num, car diceRow, car k)
{
	car m, i, j;
	if(diceRow == num + 1)
	{
		for(i = 0, j = 0; j < k; i ++, j ++)
		{
			if(j % (num + 1) != num) array2[i] = array1[j];
			else i --;
		}
	}
	else
	{
		for(i = 0, j = 0; j < k; i++, j ++)
		{
			m = j % (num + 1);
			if(m == num) i --;
			else if(m == (diceRow - 1)) array2[i] = array1[j - diceRow + num + 1];
			else array2[i] = array1[j];
		}
	}
}

double GetDenominator(const double *array, car num)
{
	double result = 1.0;
	car row;
	for(row = 1; num >= row; row ++)
	{
		result *= array[row + (row - 1) * num - 1];
	}
	return result;
}

void ZeroUndertriangle(double *array, car num)
{
	car row, i, k, n, l;
	double m;
	for(row = 1; row < num; row ++)
	{
		for(i = row + (row - 1) * num - 1, l = i, i += num, k = row + 1; k <= num; k ++, i += num)
		{
			if(!array[l]) return;
			if(array[i])
			{
				m = array[i] / array[l];
				for(n = 0; n < num;  n ++)
				{
					array[i + n] -= (array[l + n] * m);
				}
			}
		}
	}
}











	
