#ifndef _CPOINT_H_

#define _CPOINT_H_

#include "POINT.H"

class CPOINT: public POINT
{
public:
	CPOINT(int x = 200, int y = 300, int color = 1);
	void Show();
private:
	int color;
};

#endif