#ifndef _POINT_H_

#define _POINT_H_

#include <graphics.h>

class POINT
{
public:
	POINT(int x = 1, int y = 1);
	void Show(int color = 15);
protected:
	int x, y;
};

#endif