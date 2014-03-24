#ifndef _FRACTION_H_

#define _FRACTION_H_

//#include <iostream>

//using namespace std;

class FRACTION
{
public:
	FRACTION(int dence = 0, int numerator = 1);
	friend istream& operator >>(istream& in, FRACTION &x);
	friend ostream& operator <<(ostream& out, const FRACTION &x);
	FRACTION operator +(const FRACTION &x);
	FRACTION operator -(const FRACTION &x);
	FRACTION operator *(const FRACTION &x);
	FRACTION operator /(const FRACTION &x);
private:
	int numerator, dence;
};

#endif
