#include <iostream>

using namespace std;

#include <string>

#include "CYCLE_QUEUE.H"

int Test(const int& x)
{
	return x *2;
}

int main()
{
	CYCLE_QUEUE<int> a;
	a.EnQueue(1);
	a.EnQueue(2);
	a.EnQueue(3);
	a.Display();
	cout << endl;
	cout << a.DeQueue() << endl;
	a.Display();
	cout << endl;
	CYCLE_QUEUE<int> b(a);
	b.Display();
	cout << endl;
	CYCLE_QUEUE<int> c;
	c = a;
	c.Display();
	cout << endl;
	cout << c.Top() << endl;
	a.Clear();
	a.EnQueue(100);
	a.Display();
	cout << endl;
	return 0;	
}