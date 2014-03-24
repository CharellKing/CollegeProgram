#ifndef _MYCOORD_H_

#define _MYCOORD_H_

class COORD
{
private:
	double x_coord, y_coord;
public:
	void Set(double x, double y);
	void Get(double &x, double &y);
	void SetX(double x);
	void SetY(double y);
	double GetX();
	double GetY();
	void Input();
	void Output() const;
	double Distance(const COORD &b);
};

#endif