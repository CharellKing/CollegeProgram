#include <iostream>

using namespace std;

#include "MYVECTOR.H"

int main()
{
MYVECTOR a(4), b(4), c(3);
cout << "a = ? "; cin >> a;
cout << "b = ? "; cin >> b;
cout << "c = ? "; cin >> c;
if (a == b) cout << "a == b\n";
if (a != b) cout << "a != b\n";
if (a == c) cout << "a == c\n";
if (a != c) cout << "a != c\n";
//if (a == 5) cout << "a == b\n"; // ±àÒë´íÎó, É¾³ý´Ë¾ä
//if (5 != a) cout << "a != b\n"; // ±àÒë´íÎó, É¾³ý´Ë¾ä





return 0;
}