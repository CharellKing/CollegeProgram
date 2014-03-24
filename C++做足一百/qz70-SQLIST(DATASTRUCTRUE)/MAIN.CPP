#include <iostream>

using namespace std;

#include "SQLIST.H"

int main()
{
	SQLIST a;
	a.Insert(2);
	a.Insert(3);
	a.Insert(1);
	a.Insert(0);
	a.Insert(-4);
	a.Output();
	cout << endl;
	return 0;
}
