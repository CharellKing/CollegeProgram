#include <iostream>

using namespace std;

#include "C_LINKLIST.H"

int main()
{
	C_LINKLIST<int> a, b;
	a.Insert(1);
	a.Insert(2);
	a.Insert(0);
	a.Insert(-1);
	a.Append(3, 5);
	a.Display();
	cout << endl;
	b.Insert(1);
	b = a;
	b.Display();
	cout << endl;
	C_LINKLIST<int> c(a);
	c.Display();
	cout << endl;
	a.Clear();
	a.Insert(1);
	a.Display();
	cout << endl;
	return 0;	
}