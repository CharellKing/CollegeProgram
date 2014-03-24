#include <iostream>

using namespace std;

#include "QUEUE.H"

int Test(const int& x)
{
	return x * 2;
}

int main()
{
	try
	{
		QUEUE<int> a, b;
		a.EnQueue(1);
		a.EnQueue(2);
		a.EnQueue(3);
		cout << a.DeQueue() << endl;
		a.Display();
		cout << endl;
		b = a.Traverse(&Test);
		b.Display();
		cout << endl;
	}
	catch(string x)
	{
		cout << x << endl;
	}
	return 0;	
}
