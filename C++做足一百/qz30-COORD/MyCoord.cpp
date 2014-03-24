#include <iostream>

using namespace std;

#include <cmath>

#include "MyCoord.h"

void COORD:: Set(double x, double y)
{
	x_coord = x;  y_coord = y;
}

void COORD:: Get(double &x, double &y)
{
	x = x_coord; y = y_coord;
}

void COORD:: SetX(double x)
{
	x_coord = x;
}
void COORD:: SetY(double y)
{
	y_coord = y;
}

double COORD:: GetX()
{
	return x_coord;
}

double COORD:: GetY()
{
	return y_coord;
}

void COORD:: Input()
{
	cin >> x_coord >> y_coord;
}

void COORD:: Output() const
{
	cout << "(" << x_coord << "," << y_coord << ")";
}

double COORD::Distance(const COORD &b)
{
	double X = b.x_coord - x_coord, Y = b.y_coord - y_coord;
	return sqrt(X * X + Y * Y);
}
