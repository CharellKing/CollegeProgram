#include <iostream>

using namespace std;

#include "FRACTION.H"

#include "MYMATH.H"

FRACTION::FRACTION(int dence, int numerator)
{
	if(numerator) this->numerator = numerator, this->dence = dence;
	else this->numerator = 1, this->dence = 10e6, cout << "´íÎó!" << endl;
}

istream& operator >>(istream& in, FRACTION &x)
{
	int numerator, dence;
	while(cin >> dence >> numerator, !numerator) cout << "ÇëÖØÐÂÊäÈë:" << endl;
	x.numerator = numerator, x.dence = dence;
	return in;
}



ostream& operator <<(ostream& out, const FRACTION &x)
{
	int numerator, dence, n;
	if(x.dence)
	{
		n = Gcd(x.numerator, x.dence);
		numerator = x.numerator / n;
		dence = x.dence / n;
		if(numerator == 1) cout << dence << endl;
		else if(numerator == -1) cout << -dence << endl;
		else if(numerator * dence > 0) cout << Abs(dence) << '/' <<Abs(numerator) << endl;
		else cout << -Abs(dence) << '/' << Abs(numerator) << endl;
	}
	else
	{
		cout << '0' << endl;
	}
	return out;
}
		
FRACTION FRACTION::operator +(const FRACTION &x)
{

	return FRACTION(this->dence * x.numerator + x.dence * this->numerator, this->numerator * x.numerator);
}

FRACTION FRACTION::operator -(const FRACTION &x)
{
	return FRACTION(this->dence * x.numerator - x.dence * this->numerator, this->numerator * x.numerator);
}

FRACTION FRACTION::operator *(const FRACTION &x)
{
	return FRACTION(this->dence * x.dence, this->numerator * x.numerator);
}

FRACTION FRACTION::operator /(const FRACTION &x)
{
	if(x.dence == 0)
	{
		cout << "³ýÁã´íÎó!" << endl;
		return FRACTION(10E7, 1);
	}
	else
	{
		return FRACTION(this->dence * x.numerator, this->numerator * x.dence);
	}
}

