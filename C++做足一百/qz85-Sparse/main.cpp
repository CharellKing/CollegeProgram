#include <iostream>

using namespace std;

#include "Sparse.h"

int main()
{
	try
	{
		Sparse<int> a(3, 4), b(4, 3), c;
		a.Input();
		b.Input();
		c = a.Mul(b);
		c.Output();
		cout << endl;
	}
	catch(string x)
	{
		cout << x << endl;
	}
	return 0;
}
