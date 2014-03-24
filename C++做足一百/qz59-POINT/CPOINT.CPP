#include <iostream.h>

#include "CPOINT.H"

CPOINT::CPOINT(int x, int y, int color) : POINT(x, y), color(color)
{
}

void CPOINT::Show()
{
	POINT::Show(color);
}