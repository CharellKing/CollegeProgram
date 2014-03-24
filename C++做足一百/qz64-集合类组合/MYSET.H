#ifndef _MYSET_H_

#define _MYSET_H_

class MYSET
{
public:
	MYSET();
	virtual ~MYSET() = 0{}
	virtual void Append(double x) = 0;
	virtual int Cardinal()const = 0;
	virtual bool IsEmpty()const = 0;
	virtual void Input() = 0;
	virtual void Output()const = 0;
	virtual void Remove(double x) = 0;
	virtual int Find(double x)const = 0;
	virtual bool Exist(double x)const = 0;
	virtual void Add(const MYSET &x, MYSET &y)const = 0;
	virtual void Sub(const MYSET &x, MYSET &y)const = 0;
	virtual void Mul(const MYSET &x, MYSET &y)const = 0;
	virtual double operator()(int i)const = 0;
	virtual MYSET& operator=(const MYSET &x) = 0;
	virtual void Clear() = 0;
protected:
	int cardinal;
};


#endif