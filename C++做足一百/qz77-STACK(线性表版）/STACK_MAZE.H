#ifndef _STACK_MAZE_H_

#define _STACK_MAZE_H_

#include "STACK.H"

#include "COORD.H"

bool IsValid(const MYCOORD<int>& b);

bool IsDeadCorner(MYCOORD<int> x);

void Maze();

void Path();

#endif