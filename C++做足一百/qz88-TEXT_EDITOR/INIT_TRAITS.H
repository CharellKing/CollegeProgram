#ifndef _INIT_TRAITS_H_

#define _INIT_TRAITS_H_

template <typename T>
class Init_Traits;

template <>
class Init_Traits<char>
{
public:
	static char Init()
	{
		return 0;
	}
};

template <>
class Init_Traits<int>
{
public:
	static int Init()
	{
		return 0;
	}
};

template <>
class Init_Traits<float>
{
public:
	static float Init()
	{
		return 0.0;
	}
};

template <>
class Init_Traits<double>
{
public:
	static double Init()
	{
		return 0.0;
	}
};

#endif
