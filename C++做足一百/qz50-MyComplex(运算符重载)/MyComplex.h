#ifndef _MYCOMPLEX_H_
#define _MYCOMPLEX_H_

class MYCOMPLEX
{
public:
	MYCOMPLEX(double real = 0, double imaginary = 0);
	MYCOMPLEX(const MYCOMPLEX &x);
	~MYCOMPLEX();
	const MYCOMPLEX& operator =(const MYCOMPLEX &x);

	void Set(double real, double imaginary = 0);
	void Get(double &real, double &imaginary) const;
	void Real(double real);
	double Real() const;
	void Imaginary(double imaginary);
	double Imaginary() const;

	void Input();
	void Output() const;

	friend istream& operator >>(istream &in, MYCOMPLEX &x);
	friend ostream& operator <<(ostream &out, const MYCOMPLEX &x);
//	friend MYCOMPLEX operator +(const MYCOMPLEX &x);
	MYCOMPLEX operator -(const MYCOMPLEX &x)const;
	MYCOMPLEX operator *(const MYCOMPLEX &x)const;
	MYCOMPLEX operator /(const MYCOMPLEX &x)const;
	
//	MYCOMPLEX Add(const MYCOMPLEX &x) const;
	MYCOMPLEX operator +(const MYCOMPLEX &x) const;

private:
	double real, imaginary;
};

#endif