#ifndef _MYSET_H

#define _MYSET_H

class MYSET
{
public:
	MYSET(int size = 100);
	MYSET(const MYSET &x);
	~MYSET();
	void Append(double x);
	bool IsEmpty();
	int Cardinal();
	void Input();
	void Output();
	void Remove(double x);
	int Find(double x);
	bool Exist(double x);
	double Get(int position);
	double* Get();
	MYSET Add(MYSET &x);
	MYSET Sub(MYSET &x);
	MYSET Mul(MYSET &x);
	MYSET& operator=(const MYSET &x);
	void Clear();
private:
	double *elements;
	int cardinal, size;
};
#endif