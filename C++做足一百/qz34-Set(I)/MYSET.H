#ifndef _MYSET_H

#define _MYSET_H

class MYSET
{
public:
	MYSET(int size = 100);
	~MYSET() { }
	void Append(const double x);
	bool IsEmpty();
	int Cardinal();
	void Input();
	void Output();
	void Remove(const double x);
	int Find(const double x);
	bool Exist(const double x);
	double Get(int position);
	double* Get();
	MYSET Add(MYSET &x);
	MYSET Sub(MYSET &x);
	MYSET Mul(MYSET &x);
	void Clear();
private:
	double *elements;
	int cardinal, size;
};
#endif