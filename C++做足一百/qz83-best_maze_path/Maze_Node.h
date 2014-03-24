#ifndef _Maze_Node_H_

#define _Maze_Node_H_

#include "Coord.h"

struct MazeNode
{
	MazeNode(int row = -1, int column = -1 , int prep = -1);
	Coord coord;
	int prep;
};

#endif