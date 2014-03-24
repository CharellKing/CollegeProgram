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
		cout << "请输入迷宫的行数和列数:" << endl;
		cin >> row >> column;
		cout << "请设置迷宫:('.'表示通道, '#'表示墙壁)" << endl;
		a.MazeLayOut(row, column);
		cout << "请输入起点的位置:";
		cin >> start.row >> start.column;
		cout << "请输入终点的位置:";
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