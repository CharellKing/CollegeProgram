#include <iostream>

using namespace std;

#include "FRACTION.H"

int main()
{
	FRACTION a, b;
	cout << " a = ?" << endl;
	cin >> a;
	cout << "a = " << a << endl;
	cout << " b = ?" << endl;
	cin >> b;
	cout << "b = " << b << endl;
	cout << "ºÍ: " << endl;
	cout << a + b << endl;
	cout << "²î: " << endl;
	cout << a - b << endl;
	cout << "»ý: " << endl;
	cout << a * b << endl;
	cout << "ÉÌ: " << endl;
	cout << a / b << endl;
	return 0;
}