#ifndef _MYMATH_H_
#define _MYMATH_H_

template <typename T>
T Abs(T m)
{
	return (m < 0 ? -m : m);
}

template <typename T>
T Gcd(T m, T n)
// 求整数m和n的最大公约数
{
	T y;
	if(m == 0)
	{
		y = 1;
	}

	if(n == 0)
	{
		y = m;
	}
	else
	{
		y = Gcd(n, m % n);
	}
	return y;
}

#endif
