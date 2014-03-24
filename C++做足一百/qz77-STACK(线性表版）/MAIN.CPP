#include <iostream>

using namespace std;

#include "STACK_MAZE.H"

int Test(const int& x)
{
	return x * 2;
}

int main()
{
	/*try
	{
		STACK<int> a, b;
		a.Push(1);
		a.Push(2);
		a.Push(3);
		cout << a.IsEmpty() << endl;
		a.Pop();
		b = a.Traverse(&Test);
		b.Display();
		cout << endl;
	}
	catch(string x)
	{
		cout << x << endl;
	}
	*/
	/*string str;
	str = Edlin();
	cout << str;
	*/
	try
	{
		Maze();
		Path();
	}
	catch(string x)
	{
		cout << x << endl;
	}
	return 0;	
}
