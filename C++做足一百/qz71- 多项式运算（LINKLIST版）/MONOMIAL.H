/*---------MONOMIAL.H--------
  数据操作：
  

  成员数据：
  exponent:指数;
  coefficient:系数(可能为int，也可能为double)
----------------------------*/

#ifndef _MONOMIAL_H_

#define _MONOMIAL_H_

template <typename T>
class MONOMIAL
{
public:
	MONOMIAL(const T& coefficient = T(), int exponent = 0);
	MONOMIAL(const MONOMIAL& x);
	MONOMIAL& operator =(const MONOMIAL& x);
	bool operator == (const MONOMIAL& x)const;
	bool operator != (const MONOMIAL& x)const;
	bool operator > (const MONOMIAL& x)const;
	bool operator < (const MONOMIAL& x)const;
	MONOMIAL operator -()const;
	MONOMIAL operator +(const MONOMIAL& x)const;
	MONOMIAL operator -(const MONOMIAL& x)const;
	MONOMIAL operator *(const MONOMIAL& x)const;
	void Exponent(int exponent);
	void Coefficient(const T& x);
	int Exponent()const;
	T Coefficient()const;
	friend ostream& operator <<(ostream& out, const MONOMIAL& x);
protected:
	int exponent;
	T coefficient;
};

template <typename T>
MONOMIAL<T>::MONOMIAL(const T& coefficient, int exponent)
:coefficient(coefficient), exponent(exponent)
{
	
}

template <typename T>
MONOMIAL<T>::MONOMIAL(const MONOMIAL<T>& x)
{
	exponent = x.exponent;
	coefficient = x.coefficient;
}

template <typename T>
MONOMIAL<T>& MONOMIAL<T>::operator =(const MONOMIAL<T>& x)
{
	exponent = x.exponent;
	coefficient = x.coefficient;
	return *this;
}

template <typename T>
bool MONOMIAL<T>::operator == (const MONOMIAL<T>& x)const
{
	return x.exponent == exponent;
}

template <typename T>
bool MONOMIAL<T>::operator != (const MONOMIAL<T>& x)const
{
	return x.exponent != exponent;
}

template <typename T>
bool MONOMIAL<T>::operator > (const MONOMIAL<T>& x)const
{
	return exponent > x.exponent;
}
	
template <typename T>
bool MONOMIAL<T>::operator < (const MONOMIAL<T>& x)const
{
	return exponent < x.exponent;
}

template <typename T>
MONOMIAL<T> MONOMIAL<T>::operator -()const
{
	return MONOMIAL<T>(-coefficient, exponent);
}

template <typename T>	
MONOMIAL<T> MONOMIAL<T>::operator +(const MONOMIAL<T>& x)const
{
	if(x != *this)
	{
		throw string("它们不是同项式，不能相加!");
	}
	else
	{
		return MONOMIAL<T>(coefficient + x.coefficient, x.exponent);
	}
}


template <typename T>
MONOMIAL<T> MONOMIAL<T>::operator -(const MONOMIAL& x)const
{
	if((*this) != x)
	{
		throw string("它们不是同项式，不能相减!");
	}
	else
	{
		return MONOMIAL<T>(coefficient - x.coefficient, x.exponent);
	}
}
	
template <typename T>
MONOMIAL<T> MONOMIAL<T>::operator *(const MONOMIAL& x)const
{
	return MONOMIAL<T>(x.coefficient * coefficient, x.exponent + exponent);
}

template <typename T>
void MONOMIAL<T>::Exponent(int exponent)
{
	this->exponent = exponent;
}

template <typename T>
void MONOMIAL<T>::Coefficient(const T& coefficient)
{
	this->coefficient = coefficient;
}

template <typename T>	
int MONOMIAL<T>::Exponent()const
{
	return exponent;
}

template <typename T>
T MONOMIAL<T>::Coefficient()const
{
	return coefficient;
}

template <typename T>
ostream& operator <<(ostream& out, const MONOMIAL<T>& x)
{
	out << '<' << x.coefficient << ", " << x.exponent << '>';
	return out;
}
#endif