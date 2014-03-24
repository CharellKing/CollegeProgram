#include <iostream>

using namespace std;

#include <string>

#include "Maze.h"

int main()
{
	try
	{
		Maze a;
		Coord start, end;
		int row, column;
		cout << "�������Թ�������������:" << endl;
		cin >> row >> column;
		cout << "�������Թ�:('.'��ʾͨ��, '#'��ʾǽ��)" << endl;
		a.MazeLayOut(row, column);
		cout << "����������λ��:";
		cin >> start.row >> start.column;
		cout << "�������յ��λ��:";
		cin >> end.row >> end.column;
		a.FindPath(start, end);
		a.ShowDynamicPath();
	}
	catch(string x)
	{
		cout << x << endl;
	}
	return 0;
}