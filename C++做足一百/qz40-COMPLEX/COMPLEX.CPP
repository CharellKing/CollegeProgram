#include <iostream>

using namespace std;

#include <cmath>

#include "COMPLEX.H"

COMPLEX::COMPLEX(double real, double imaginary)
{
	this->real = real, this->imaginary = imaginary;
}

void COMPLEX::Input()
{
	cin >> this->real >> this->imaginary;
}

void COMPLEX::Output()
{
	if(this->imaginary == 0) cout << this->real;
	if(this->real == 0 && this->imaginary)
	{
		if(this->imaginary != 1) cout << this->imaginary << "i";
		else cout << "i" << endl;
	}
	if(this->real && this->imaginary)
	{
		if(this->imaginary > 0)
		{
			if(this->imaginary != 1) cout << this->real << '+' << this->imaginary << 'i';
			else cout << this->real << '+' << 'i';
		}
		else
		{
			if(this->imaginary != -1) cout << this->real << this->imaginary << 'i';
			else cout << this->real << '-' << 'i';
		}
	}
}

void COMPLEX::Set(double real, double imaginary)
{
	this->real = real, this->imaginary = imaginary;
}

double COMPLEX::Real()
{
	return real;
}

double COMPLEX::Imaginary()
{
	return imaginary;
}

double COMPLEX::Abs()
{
	return sqrt(this->real * this->real + this->imaginary * this->imaginary);
}

void COMPLEX::Real(double real)
{
	this->real = real;
}

void COMPLEX::Imaginary(double imaginary)
{
	this->imaginary = imaginary;
}

COMPLEX COMPLEX::Add(const COMPLEX &x)
{
	COMPLEX y;
	y.real = real + x.real;
	y.imaginary = imaginary + x.imaginary;
	return y;
}

COMPLEX COMPLEX::Sub(const COMPLEX &x)
{
	COMPLEX y;
	y.real = real - x.real;
	y.imaginary = imaginary - x.imaginary;
	return y;
}

COMPLEX COMPLEX::Mul(const COMPLEX &x)
{	
	COMPLEX y;
	y.real = real * x.real - imaginary * x.imaginary;
	y.imaginary = real * x.imaginary + x.real * imaginary;
	return y;
}

COMPLEX COMPLEX::Div(COMPLEX &x)
{
	COMPLEX y;
	if(x.real == 0 && x.imaginary == 0) y.real = 0, y.imaginary = 0, cout << "³ýÁã´íÎó!\n";
	else
	{
		if(x.imaginary)
		{
			COMPLEX a, b, c;
			a.real = x.real, a.imaginary = (-1) * x.imaginary;
			b = x.Mul(a);
			c = Mul(a);
			y.real = c.real / b.real, y.imaginary = c.imaginary / b.real;
		}
		else y.real = real / x.real, y.imaginary = imaginary / x.real;
	}
	return y;
}