#ifndef _POLYNOMIAL_H_

#define _POLYNOMIAL_H_

#include "LINKLIST.H"

#include "MONOMIAL.H"

template <typename T>
class POLYNOMIAL
{
public:
	void Input();
	void Output();
	int Monomial_Num()const;
	POLYNOMIAL operator+(const POLYNOMIAL& x)const;
	POLYNOMIAL operator-(const POLYNOMIAL& x)const;
	POLYNOMIAL operator*(const POLYNOMIAL& x)const;
	double Sum(double value);
protected:
	LINKLIST<MONOMIAL<T> > poly;	
};

template <typename T>
void POLYNOMIAL<T>::Input()
{
	int exponent;
	T coefficient;
	MONOMIAL<T> a;
	cout << "请输入多项式以(0, 0)结束:" << endl;
	while(cin >> coefficient >> exponent, coefficient != 0 || exponent != 0)
	{
		a.Exponent(exponent);
		a.Coefficient(coefficient);
		poly.PolyInsert(a);
	}
}

template <typename T>
void POLYNOMIAL<T>::Output()
{
	poly.Display();
}

template <typename T>
int POLYNOMIAL<T>::Monomial_Num()const
{
	return poly.Cardinal();
}

template<typename T>
POLYNOMIAL<T> POLYNOMIAL<T>::operator+ (const POLYNOMIAL<T>& x)const
{
	POLYNOMIAL<T> a;
	a.poly = poly.PolyAdd(x.poly);
	return a;
}

template<typename T>
POLYNOMIAL<T> POLYNOMIAL<T>::operator-(const POLYNOMIAL<T>& x)const
{
	POLYNOMIAL<T> a;
	a.poly = poly.PolySub(x.poly);
	return a;
}

template<typename T>
POLYNOMIAL<T> POLYNOMIAL<T>::operator*(const POLYNOMIAL<T>& x)const
{
	POLYNOMIAL<T> a;
	a.poly = poly.PolyMul(x.poly);
	return a;
}

template <typename T>
double POLYNOMIAL<T>::Sum(double value)
{
	NODE<MONOMIAL<T> > *p;
	p = poly.Head();
	return poly.PolySum(p, 0, value);
}

#endif