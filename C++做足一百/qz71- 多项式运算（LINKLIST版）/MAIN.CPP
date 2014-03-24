#include <iostream>

using namespace std;

#include <iostream>

#include "POLYNOMIAL.H"

/*int main()
{
	try
	{
		LINKLIST<int> a;
		a.Insert(2);
		a.Insert(3);
		a.Insert(4);
		a.Insert(4);
		a.Insert(3);
		a.Display();
		cout << endl;
	}
	catch(const string x)
	{
		cout << x << endl;
	}
	return 0;
}*/

int main()
{
	POLYNOMIAL<int> a, b, c;
	a.Input();
	a.Output();
	cout << endl;
	b.Input();
	b.Output();
	cout << endl;
	c = a + b;
	c.Output();
	cout << endl;
	c = a - b;
	c.Output();
	cout << endl;
	c = a * b;
	c.Output();
	cout << endl;
	cout << a.Sum(2) << endl;
	return 0;
}