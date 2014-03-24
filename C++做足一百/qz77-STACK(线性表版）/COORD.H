#ifndef _MYCOORD_H_

#define _MYCOORD_H_

template <typename T>
class MYCOORD
{
public:
	MYCOORD(T x = T(), T y = T());
	MYCOORD<T>& operator =(const MYCOORD<T>& x);
	bool operator ==(const MYCOORD<T>& x)const;
	bool operator !=(const MYCOORD<T>& x)const;
	MYCOORD<T> Right_X(T delt = 1)const;
	MYCOORD<T> Left_X(T delt = 1)const;
	MYCOORD<T> Up_Y(T delt = 1)const;
	MYCOORD<T> Down_Y(T delt = 1)const;
	T X()const;
	T Y()const;
	friend ostream& operator <<(ostream& out, const MYCOORD<T>& x);
protected:
	T x, y;
};

template <typename T>
MYCOORD<T>::MYCOORD(T x, T y) : x(x), y(y)
{
}

template <typename T>
MYCOORD<T>& MYCOORD<T>::operator =(const MYCOORD<T>& a)
{
	if(this != &a)
	{
		x = a.x;
		y = a.y;
	}
	return *this;
}

template <typename T>
bool MYCOORD<T>::operator ==(const MYCOORD<T>& a)const
{
	return a.x == x && a.y == y;
}

template <typename T>
bool MYCOORD<T>::operator !=(const MYCOORD<T>& a)const
{
	return a.x != x || a.y != y;
}

template <typename T>
MYCOORD<T> MYCOORD<T>::Right_X(T delt)const
{
	MYCOORD<T> a(x, y);
	a.x += delt;
	return a;
}

template <typename T>	
MYCOORD<T> MYCOORD<T>::Left_X(T delt)const
{
	MYCOORD<T> a(x, y);
	a.x -= delt;
	return a;
}

template <typename T>
MYCOORD<T> MYCOORD<T>::Up_Y(T delt)const
{
	MYCOORD<T> a(x, y);
	a.y -= delt;
	return a;
}

template <typename T>
MYCOORD<T> MYCOORD<T>::Down_Y(T delt)const
{
	MYCOORD<T> a(x, y);
	a.y += delt;
	return a;
}

template <typename T>
T MYCOORD<T>::X()const
{
	return x;
}

template <typename T>
T MYCOORD<T>::Y()const
{
	return y;
}

template <typename T>
ostream& operator <<(ostream& out, const MYCOORD<T>& a)
{
	cout << '<'  << a.x << ", " << a.y << '>';
	return out;
}

#endif