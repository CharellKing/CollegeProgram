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
	cout << "��: " << endl;
	cout << a + b << endl;
	cout << "��: " << endl;
	cout << a - b << endl;
	cout << "��: " << endl;
	cout << a * b << endl;
	cout << "��: " << endl;
	cout << a / b << endl;
	return 0;
}