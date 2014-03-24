#include <iostream>

using namespace std;

#include "DOUBLE_LINKLIST.H"

int main()
{
	DOUBLE_LINKLIST<int> a;
	a.Insert(1);
	a.Insert(2);
	a.Insert(0);
	a.Insert(-3);
	a.Display();
	cout << endl;
	a.RDisplay();
	cout << endl;
	a.Append(5, 3);
	a.Display();
	cout << endl;
	DOUBLE_LINKLIST<int> b, c(a);
	c.Display();
	cout << endl;
	b.Insert(3);
	b.Insert(2);
	b.Display();
	cout << endl;
	b = a;
	b.Display();
	cout << endl;
	return 0;	
}