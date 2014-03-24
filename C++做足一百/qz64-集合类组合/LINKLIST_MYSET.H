#ifndef _LINKLIST_MYSET_H

#define _LINKLIST_MYSET_H

#include "MYSET.H"

#include "ARRAY_MYSET.H"

struct NODE
{
	double Aelement;
	NODE *next;
};

typedef NODE* LNODE;

class LINKLIST_MYSET:public MYSET
{
public:
	LINKLIST_MYSET();
	LINKLIST_MYSET(const LINKLIST_MYSET &x);
	~LINKLIST_MYSET();
	void Append(double x);
	bool IsEmpty()const;
	int Cardinal()const;
	void Cardinal(int a);
	void Input();
	void Output()const;
	void Remove(double x);
	int Find(double x)const;
	bool Exist(double x)const;
	void Add(const MYSET &x, MYSET &y)const;
	void Sub(const MYSET &x, MYSET &y)const;
	void Mul(const MYSET &x, MYSET &y)const;
	void Clear();
	double operator()(int i)const;
	MYSET& operator=(const MYSET &x);
private:
	LNODE head;
};

#endif