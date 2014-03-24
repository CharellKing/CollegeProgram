#include <iostream>

using namespace std;

#include "MyDate.h"

int main()
{
	/*DATE a;
	int y;
	char m, d;
	a.Set(2009);
	a.Get(y, m, d);
	cout << y << ' ' << (int)m << ' ' << (int)d << endl;
	a.Set(2009, 5);
	a.Get(y, m, d);
	cout << y << ' ' << (int)m << ' ' << (int)d << endl;
	a.Set(2009, 5, 28);
	a.Get(y, m, d);
	cout << y << ' ' << (int)m << ' ' << (int)d << endl;
	*/
	DATE a;
	cout << "a = ? "; a.Input();
	cout << "a = "; a.Output(); cout << endl;
	cout << "a = "; a.Output(false); cout << endl;
	cout << "a = "; a.Output(true); cout << endl;
	return 0;
}

