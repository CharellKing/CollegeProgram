#ifndef _DRAW_SQUARE_H_

#define _DRAW_SQUARE_H_

#include <string>

#include "ORDINATE.H"

#include "ORDER.H"

class DRAW_SQUARE
{
public:
	DRAW_SQUARE();
	void Draw(int m, int n);
	void Grids(const bool *grids);
	void Now_location(const ORDINATE &nowlocation);
private:
	void Print1(int n);
	void Print2();
	void Print3(int n);
	void Print4(int n);
	void Print(int i, int j);
	char word1[3], word2[3], word3[3];
	bool grids[M * M];
	ORDINATE now_location;
};

#endif
