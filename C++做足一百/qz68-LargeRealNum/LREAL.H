#ifndef _LREAL_H_

#define _LREAL_H_

#include <iostream>

#include <string>

#include "DEFINITION.H"

class LREAL
{
public:
	LREAL();
	~LREAL();
	LREAL(const LREAL &x);
	LREAL& operator =(const LREAL &x);
	friend istream& operator >>(istream &in, LREAL &x);
	friend ostream& operator <<(ostream &out, const LREAL &x);
	LREAL operator -() const;
	LREAL operator +() const;
	LREAL operator +(const LREAL &x) const;
	LREAL operator -(const LREAL &x) const;
	LREAL& operator -=(const LREAL &x);
	LREAL operator *(const LREAL &x) const;
	LREAL operator /(const LREAL &x) const;
	LREAL& operator ++();
	LREAL operator ++(int);
	LREAL& operator --();
	LREAL operator --(int);
	void MPoint(int n);
	static int Digit(int i);
	LREAL Precision()const;
protected:
	int PPoint(const string &sreal);
	bool IsValid(const string x);
	void Simple(string &sreal);
	void DReal(const string &sreal);
	LREAL D_Add(const LREAL &x) const;
	LREAL D_Sub(const LREAL &x) const;
	LREAL D_Mul(const LREAL &x) const;
	LREAL D_Div(const LREAL &x) const;
	int D_ABS_C(const LREAL &x) const;
	bool IsOne() const;
	bool IsNOne() const;
	bool IsZero() const;
	int left;
	int right;
	int sign;
	double *dreal;
};

#endif