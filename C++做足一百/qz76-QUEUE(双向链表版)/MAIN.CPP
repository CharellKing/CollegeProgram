#include <iostream>

using namespace std;

#include <string>

#include "LINKQUEUE.H"

int Test(const int& x)
{
	return x *2;
}

int main()
{
	try
	{
		LINKQUEUE<int> a;
		a.EnQueue(1);
		a.EnQueue(2);
		a.EnQueue(3);
		//cout << a.DeQueue() << endl;
		//cout << a.DeQueue() << endl;
		//cout << a.DeQueue() << endl;
		//cout << a.DeQueue() << endl;
		a.EnQueue(100);
		a.Display();
		cout << endl;
		LINKQUEUE<int> b(a);
		b.Display();
		cout << endl;
		cout << b.Length() << endl;
		cout << b.Head()->Data() << endl;
		b = b.Traverse(&Test);
		b.Display();
		cout << endl;
	}
	catch(string x)
	{
		cout << x << endl;
	}
	return 0;	
}