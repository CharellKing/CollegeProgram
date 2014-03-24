#include "Coord.h"

Coord::Coord(int row, int column)
{
	this->row = row;
	this->column = column;
}

bool Coord::operator != (const Coord& x)const
{
	return row != x.row || column != x.column;
}

bool Coord::operator == (const Coord& x)const
{
	return row == x.row && column == x.column;
}