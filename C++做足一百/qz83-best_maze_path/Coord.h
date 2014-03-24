#ifndef _Coord_h_

#define _Coord_h_

class Coord
{
public:
	Coord(int row = -1, int column = -1);
	bool operator != (const Coord& x)const;
	bool operator == (const Coord& x)const;
	int row;
	int column;
};

#endif