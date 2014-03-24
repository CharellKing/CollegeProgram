#ifndef _GAME_H_

#define _GAME_H_

#include <string.h>

#include "DRAW_SQUARE.H"

#include "ORDER.H"

#include "ORDINATE.H"

struct DRAW
{
	ORDINATE now_location;
	bool grids[M * M];
	char name[20];
};

struct NODE
{
	DRAW aDraw;
	NODE *next;
};

typedef NODE* LNODE;

class TURTLE_GRAPHICS
{
public:
	TURTLE_GRAPHICS();
	~TURTLE_GRAPHICS();
	void Graphics();
	void Convert_Grids();
	void Convert_Now_location();
	void Reference();
	void ReadOut();
	void Save();
	void WriteIn();
private:
	DRAW_SQUARE draw;
	ORDER order;
	LNODE head;
};
#endif