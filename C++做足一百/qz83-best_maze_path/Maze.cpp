#include <iostream>

using namespace std;

#include <string>

#include <conio.h>

#include <windows.h>

#include "Maze.h"

Maze::Maze(int row, int column)
{
	if(row <= 0 || column <= 0)
	{
		throw string("迷宫的行列布局有误!");
	}
	this->row = row;
	this->column = column;
	size = this->row * this->column;
	Create_bool(layout, this->row, this->column);
	Create_bool(passed, this->row, this->column);
	path = new MazeNode[size];
}
	
Maze::~Maze()
{
	Clear();
}

void Maze::MazeLayOut(int row, int column)
{
	int i, j;
	char c;
	if(row <= 0 || column <= 0)
	{
		throw string("迷宫的行列布局有误!");
	}
	this->row = row;
	this->column = column;
	size = this->row * this->column;
	Clear();
	Create_bool(layout, this->row, this->column);
	Create_bool(passed, this->row, this->column);
	path = new MazeNode[size];
	for(i = 0; i < row; i ++)
	{
		for(j = 0; j < column; j ++)
		{
			while(c = getch(), c != '.' && c != '#');
			cout << c;
			if(c == '.')
			{
				this->layout[i][j] = false;
			}
			else
			{
				this->layout[i][j] = true;
			}
			passed[i][j] = false;
		}
		cout << endl;
	}
}

void Maze::MazeLayOut()const
{
	UINT r, c;
	for(r = 0; r < row; r ++)
	{
		for(c = 0; c < column; c ++)
		{
			if(layout[r][c] == true)
			{
				cout << "#";
			}
			else
			{
				cout << ".";
			}
		}
		cout << endl;
	}
}

void Maze::FindPath(Coord& start, Coord& end)
{
	Coord ahead;
	MazeNode maze_node;
	int front = 0, rear = 0, back;
	char direction;
	start.row --, start.column --;
	end.row --, end.column --;
	if(IsValid(start))
	{
		maze_node.coord = start;
		maze_node.prep = -1;
		path[front ++] = maze_node;
		passed[start.row][start.column] = true;
	}
	while(rear < front && ahead != end)
	{
		for(direction = 0; direction < 4 && ahead != end; direction ++)
		{
			ahead = path[rear].coord;
			Walk(direction, ahead);
			if(IsValid(ahead))
			{
				maze_node.coord = ahead;
				maze_node.prep = rear;
				path[front++] = maze_node;
				passed[ahead.row][ahead.column] = true;
			}
		}
		rear ++;
	}
	if(path[--front].coord == end)
	{
		back = path[front].prep;
		path[front].prep = -1;
		while(back >= 0)
		{
			rear = path[back].prep;
			path[back].prep = front;
			front = back;
			back = rear;
			 
		}
	}
}

bool Maze::IsValid(const Coord& x)const
{
	return x.row >= 0 && x.row < row &&
		x.column >= 0 && x.column < column &&
		passed[x.row][x.column] == false &&
		layout[x.row][x.column] == false;
}

void Maze::Walk(char direction, Coord& x)
{
	switch(direction)
	{
	case 0:
		x.row --;
		break;
	case 1:
		x.column ++;
		break;
	case 2:
		x.row ++;
		break;
	case 3:
		x.column --;
		break;
	}
}

void Maze::Clear()
{
	Clear_bool(layout);
	Clear_bool(passed);
	delete [] path;
}

void Maze::Clear_bool(bool**& p)
{
	delete [] p;
}

void Maze::Create_bool(bool** &p, UINT row, UINT column)
{
	int i;
	p = new bool_pointer[row];
	for(i = 0; i < row; i ++)
	{
		p[i] = new bool [column];
	}
}

void Maze::ShowDynamicPath()const
{
	int prep = 0, i, j, k = 1;
	while(prep != -1)
	{
		cout << "第" << k ++ << "步:" << endl;
		for(i = 0; i < row; i ++)
		{
			for(j = 0; j < column; j ++)
			{
				if(i == path[prep].coord.row
					&& j == path[prep].coord.column)
				{
					cout << (char)3;
				}
				else if(layout[i][j] == false)
				{
					cout << '.';
				}
				else
				{
					cout << '#';
				}
			}
			cout << endl;
		}
		cout << endl;
		prep = path[prep].prep;
		Sleep(1000);
	}
}
