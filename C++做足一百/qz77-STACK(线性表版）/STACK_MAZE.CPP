#include <iostream>

using namespace std;

#include <windows.h>

#include "STACK_MAZE.H"

const int row = 10;

const int column = 10;

const bool layout[row][column] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
								  0, 1, 1, 0, 1, 1, 1, 0, 1, 0,
								  0, 1, 1, 0, 1, 1, 1, 0, 1, 0,
								  0, 1, 1, 1, 1, 0, 0, 1, 1, 0,
								  0, 1, 0, 0, 0, 1, 1, 1, 1, 0,
								  0, 1, 1, 1, 0, 1, 1, 1, 1, 0,
								  0, 1, 0, 1, 1, 1, 0, 1, 1, 0,
								  0, 1, 0, 0, 0, 1, 0, 0, 1, 0,
								  0, 0, 1, 1, 1, 1, 1, 1, 1, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

const MYCOORD<int> start(1, 1), end(8, 8);

MYCOORD<int> dead_corner[row * column];
int p = 0;

STACK<MYCOORD<int> > mazepath;

bool IsValid(const MYCOORD<int>& b)
{
	return b.X() >= 0 && b.X() <= column && b.Y() >= 0 && b.Y() <= row && layout[b.Y()][b.X()];
}
bool IsDeadCorner(MYCOORD<int> x)
{
	int i = 0;
	for(i = 0; i < p; i ++)
	{
		if(dead_corner[i] == x)
		{
			return true;
		}
	}
	return false;
}

void Maze()
{
	MYCOORD<int> present, next(start);
	int direction;
	do
	{
		if(!IsDeadCorner(next) && IsValid(next) && !mazepath.IsExist(next))
		{
			present = next;
			mazepath.Push(present);
			if(present == end) break;
			direction = 1;
			next = present.Right_X();
		}
		else
		{
			direction ++;
			if(direction == 2)
			{
				next = present.Down_Y();
			}
			else if(direction == 3)
			{
				next = present.Left_X();
			}
			else if(direction == 4)
			{
				next = present.Up_Y();
			}
			else
			{
				dead_corner[p] = mazepath.Pop();
				if(mazepath.IsEmpty()) break;
				present = mazepath.Top();
				next = present;
				p ++;
				direction = 1;
			}
		}
	}
	while(!mazepath.IsEmpty());
}

void Path()
{
	int i, j, k;
	//cout << mazepath.Length() << endl;
	//mazepath.Display();
	//cout << endl;
	for(k = 1; k <= mazepath.Length(); k ++)
	{
		cout << "µÚ" << k << "²½" << endl;
		for(i = 0; i < row; i ++)
		{
			for(j = 0; j < column; j ++)
			{
				if(MYCOORD<int>(j, i) == mazepath[k])
				{
					cout << (char)3 << ' ';
				}
				else if(layout[i][j])
				{
					cout << '.' << ' ';
				}
				else
				{
					cout << '#' << ' ';
				}
			}
			cout << endl;
		}
		cout << endl;
		Sleep(1000);
	}
}