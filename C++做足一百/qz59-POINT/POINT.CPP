#include <iostream.h>

#include "POINT.H"


POINT::POINT(int x, int y): x(x), y(y)
{
}

void POINT::Show(int color)
{
	setcolor(color);
	moveto(x, y);
}
