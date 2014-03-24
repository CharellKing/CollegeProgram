#include <iostream>

using namespace std;

#include "BST.H"

int main()
{
	int i;
	BST<double> a;
	/*
	a.Insert(5);
	a.Insert(6);
	a.Insert(7);
	a.Insert(8);
	a.Insert(1);
	a.Insert(2);
	a.Insert(3);
	a.Insert(4);
	a.Insert(9);
	a.Insert(1);
	a.Insert(3);
	a.Insert(2);
	a.Insert(0);
	*/

	/*
	a.Insert(1);
	a.Insert(1);
	a.Insert(1);
	a.Insert(1);
	a.Insert(1);
	*/
	a.Insert(5);
	a.Insert(4);
	a.Insert(6);
	a.Insert(3);
	a.Insert(5);
	a.Insert(5.7);
	//a.Insert(5.6);
	//a.Insert(5.8);
	a.Insert(7);
	a.Display();

	cout << endl;
	i = a.Tree_type1();
	if(i == 0)
	{
		cout << "此树为满二叉树!" << endl;
	}
	else if(i == 1)
	{
		cout << "此树为完全二叉树!" << endl;
	}
	else if(i == 2)
	{
		cout << "非完全二叉树!" << endl;
	}
	else
	{
		cout << "空树!" << endl;
	}
	//a.Remove(5);
	//a.Display();
	//cout << endl;
	return 0;	
}