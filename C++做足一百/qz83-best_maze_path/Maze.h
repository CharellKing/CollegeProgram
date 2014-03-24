#ifndef _Maze_h_

#define _Maze_h_

#include "Maze_Node.h"

typedef unsigned UINT;

typedef bool* bool_pointer;

const UINT INIT_ROW = 1;

const UINT INIT_COLUMN = 1;

class Maze
{
public:
	Maze(int row = INIT_ROW, int column = INIT_COLUMN);
	~Maze();
	void MazeLayOut(int row, int column);
	void MazeLayOut()const;
	void FindPath(Coord& start, Coord& end);
	bool IsValid(const Coord& x)const;
	static void Walk(char direction, Coord& x);
	void ShowDynamicPath()const;
protected:
	static void Clear_bool(bool**& p);
	static void Create_bool(bool** &p, UINT row, UINT column);
	void Clear();
	bool_pointer *layout, *passed;
	UINT row, column, size;
	MazeNode* path;
};
	

#endif