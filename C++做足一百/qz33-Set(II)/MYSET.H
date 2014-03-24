#ifndef _MYSET_H

#define _MYSET_H

struct NODE
{
	double Aelement;
	NODE *next;
};

typedef NODE* LNODE;

class MYSET
{
public:
	MYSET();
	~MYSET(){}
	void Append(double x);
	bool IsEmpty();
	int Cardinal();
	void Cardinal(int a);
	void Input();
	void Output();
	void Remove(double x);
	int Find(double x);
	bool Exist(double x);
	double Get(int position);
	LNODE GetHead();
	MYSET Add(MYSET &x);
	MYSET Sub(MYSET &x);
	MYSET Mul(MYSET &x);
	void Clear();
private:
	LNODE head;
	int cardinal;
};

#endif