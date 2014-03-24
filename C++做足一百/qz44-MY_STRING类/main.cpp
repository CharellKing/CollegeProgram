#include <iostream>

using namespace std;

#include "MY_STRING.H"

int main()
{
	char *s;
	int i;
	MY_STRING a;
	cout << a << endl;
	cout << a.Size() << endl;
	MY_STRING b = "ab";
	cout << b << endl;
	cout << b.Size() << endl;
	MY_STRING c("abc");
	cout << c << endl;
	cout << c.Size() << endl;
	MY_STRING d;
	d = a;
	cout << d << endl;
	cout << d.Size() << endl;
	s = a.StringToCharArray();
	for(i = 0; s[i]; i ++) cout << s[i];
	cout << endl;
	return 0;
}
