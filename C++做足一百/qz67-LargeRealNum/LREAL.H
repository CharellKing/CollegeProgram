#ifndef _LREAL_H_

#define _LREAL_H_

#include <string>

#include "DEFINITION.H"

class LREAL
{
public:
	LREAL();
	LREAL(const LREAL &x);
	LREAL& operator =(const LREAL &x);
	friend ostream& operator <<(ostream &out, const LREAL &x);
	friend istream& operator >>(istream &in, LREAL &x);
	int APoint() const;
	LREAL operator +(const LREAL &x) const;
	LREAL& operator +=(const LREAL &x);
	LREAL operator -(const LREAL &x) const;
	LREAL operator *(const LREAL &x) const;
	LREAL operator /(const LREAL &x) const;
	LREAL operator -()const;
	LREAL operator +()const;
	int PPoint()const;
	bool IsZero()const;
	bool IsOne()const;
	bool IsNOne()const;

protected:
	static string IAdd(const string &x, const string &y);
	static string ISub(const string &x, const string &y);
	static string IMul(const string &x, const string &y);
	static string IDiv(const string &x, const string &y, int m);
	static void Digit_Char(string &x);
	static void Char_Digit(string &x);
	static int I_ABS_C(const string &x, const string &y);
	static void Digit(string &x);
	static bool IsValid(const string real);
	static string ADigit(const string &x, int n);
	static string MDigit(const string &x, int n);
	LREAL MPoint(int right)const;
	void Simple();
	static void Reserve(string& x);
	static void Swap(string &a, string &b);
	int sign;
	string real;
};


#endif 
