#ifndef _ARRAY_MYSET_H

#define _ARRAY_MYSET_H

#include "MYSET.H"

#include "LINKLIST_MYSET.H"

class ARRAY_MYSET:public MYSET
{
public:
	ARRAY_MYSET(int size = 100);
	ARRAY_MYSET(const ARRAY_MYSET &x);
	~ARRAY_MYSET();
	void Append(double x);
	bool IsEmpty()const;
	int Cardinal()const;
	void Input();
	void Output()const;
	void Remove(double x);
	int Find(double x)const;
	bool Exist(double x)const;
	void Add(const MYSET &x, MYSET &y)const;
	void Sub(const MYSET &x, MYSET &y)const;
	void Mul(const MYSET &x, MYSET &y)const;
	double operator()(int i)const;
	MYSET& operator=(const MYSET &x);
	void Clear();
protected:
	double *elements;
	int size;
};
#endif