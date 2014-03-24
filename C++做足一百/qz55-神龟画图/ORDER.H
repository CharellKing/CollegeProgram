#ifndef _ORDER_H_

#define _ORDER_H_

#include "MyMenu.h"

#include "ORDINATE.H"

class ORDER
{
public:
	ORDER();
	void Steps();
	char Orient();
	void Move();
	ORDINATE Now_location() const;
	const bool* Grids() const;
	int X();
	int Y();
private:
	void Cover1();
	void Cover2();
	void Cover3();
	void Cover4();
	void Cover5();
	void Restriction();
	bool grids[M * M], last_grids[M * M];
	char steps, orient, last_orient;
	ORDINATE now_location;
	ORDINATE last_location;
	char pen_point;
};

#endif
