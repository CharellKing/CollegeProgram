#include <iostream>

using namespace std;

#include <conio.h>

#include "STACK.H"

int Test(const int x)
{
	return x * 2;
}

int main()
{
	try
	{
		STACK<int> a, b;
		a.Push(1);
		a.Push(2);
		a.Push(3);
		a.Clear();
		a.Pop();
		b = a.Traverse(&Test);
		b.Display();
		cout << endl;
	}
	catch(string x)
	{
		cout << x << endl;
	}
	getch();
	return 0;	
}
