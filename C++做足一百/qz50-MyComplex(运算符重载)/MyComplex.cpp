#include <iostream>
using namespace std;
#include "MyComplex.h"
//分子numerator
//denominator
MYCOMPLEX::MYCOMPLEX(double real, double imaginary)
{
	this->real = real;
	this->imaginary = imaginary;
	cout << "创建(" << real << ", " << imaginary << ")\n";
}

MYCOMPLEX::MYCOMPLEX(const MYCOMPLEX &x)
{
	real = x.real; imaginary = x.imaginary;
	cout << "克隆(" << real << ", " << imaginary << ")\n";
}

MYCOMPLEX::~MYCOMPLEX()
{
	cout << "销毁(" << real << ", " << imaginary << ")\n";
}

const MYCOMPLEX& MYCOMPLEX::operator =(const MYCOMPLEX &x)
{
	real = x.real; imaginary = x.imaginary;
	cout << "赋值(" << real << ", " << imaginary << ")\n";
	return *this;
}

void MYCOMPLEX::Set(double real, double imaginary)
{
	this->real = real;
	this->imaginary = imaginary;
}

void MYCOMPLEX::Get(double &real, double &imaginary) const
{
	real = this->real;
	imaginary = this->imaginary;
}

void MYCOMPLEX::Real(double real)
{
	this->real = real;
}

double MYCOMPLEX::Real() const
{
	return real;
}

void MYCOMPLEX::Imaginary(double imaginary)
{
	this->imaginary = imaginary;
}

double MYCOMPLEX::Imaginary() const
{
	return imaginary;
}

void MYCOMPLEX::Input()
{
	cin >> real >> imaginary;
}

void MYCOMPLEX::Output() const
{
	cout << "(" << real << ", " << imaginary << ")";
}

istream& operator >>(istream &in, MYCOMPLEX &x)
{
	in >> x.real >> x.imaginary;
	return in;
}

ostream& operator <<(ostream &out, const MYCOMPLEX &x)
{
	out << "(" << x.real << ", " << x.imaginary << ")";
	return out;
}

/*
MYCOMPLEX MYCOMPLEX::Add(const MYCOMPLEX &x) const
{
	return MYCOMPLEX(real + x.real, imaginary + x.imaginary);
}
*/

MYCOMPLEX MYCOMPLEX::operator +(const MYCOMPLEX &x) const
{
	return MYCOMPLEX(real + x.real, imaginary + x.imaginary);
}


	
MYCOMPLEX MYCOMPLEX::operator -(const MYCOMPLEX &x)const
{
	return MYCOMPLEX(real - x.real, imaginary - x.imaginary);
}

MYCOMPLEX MYCOMPLEX::operator *(const MYCOMPLEX &x)const
{
	return MYCOMPLEX(real * x.real - imaginary * x.imaginary, real * x.imaginary + imaginary * x.real);
}

MYCOMPLEX MYCOMPLEX::operator /(const MYCOMPLEX &x)const
{
	MYCOMPLEX z, y(x.real, -x.imaginary);
	double m;
	if(real == 0 && imaginary == 0) cout << "错误!" << endl;
	else
	{
		m = x.real * x.real + x.imaginary * x.imaginary;
		z = y * (*this);
		return MYCOMPLEX(z.real / m, z.imaginary / m);
	}
	return z;
}