#include <iostream>

using namespace std;

#include <cfloat>

const int Volume = 50;

double MyMin(double *array, int start, int end)
{
	int mid;
	double min1, min2, min;
	if(start == end) min = array[start - 1];
	else
	{
		mid = (start + end) / 2;
		min1 = MyMin(array, start, mid);
		min2 = MyMin(array, mid + 1, end);
		min1 < min2 ? min = min1 : min = min2;
	}
	return min;
}

int main()
{
	char c, i = 0;
	double array[Volume], x;
	array[0] = DBL_MAX;
	do
	{
		while(c = cin.get(), isspace(x) && c != '\n');
		if(c != '\n')
		{
			cin.putback(c);
			cin >> x;
			if(cin) array[i ++] = x;
			else
			{
				cin.clear();
				cin.sync();
			}
		}
	}
	while(c != '\n');
	if(i == 0) i ++;
	for(int j = 0; j < i; j ++)  cout << array[j] << ' ';
	cout << endl;
	cout << "MIN :" << MyMin(array, 1, i) << endl;
	return 0;
}


