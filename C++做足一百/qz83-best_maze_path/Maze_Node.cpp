#include "Maze_Node.h"

MazeNode::MazeNode(int row, int column, int prep) : coord(row, column)
{
	this->prep = prep;
}