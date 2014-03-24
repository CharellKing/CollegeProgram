#ifndef _MYVECTOR_H_

#define _MYVECTOR_H_

#include <iostream>

using namespace std;

#include "NODE.H"

class MYVECTOR
{
public:
	explicit MYVECTOR(int dimension = 2); // 创建2维零向量
	MYVECTOR(const MYVECTOR& x);
	~MYVECTOR();
	int Dimension()const; // 读取向量维数
	friend istream& operator >>(istream& in, MYVECTOR& x);
	friend ostream& operator <<(ostream& out, const MYVECTOR& x);
	const MYVECTOR& operator =(const MYVECTOR& x);
	const MYVECTOR& operator =(double x);
	double& operator [](int i);
	MYVECTOR& operator +=(MYVECTOR& x);
	MYVECTOR& operator -=(MYVECTOR& x);
	MYVECTOR operator +(MYVECTOR& x) const;
	MYVECTOR operator -(MYVECTOR& x) const;
	double operator *(MYVECTOR& x);
	MYVECTOR operator *(double y) const;
	friend MYVECTOR operator *(double y, const MYVECTOR& x);
	MYVECTOR operator +() const;
	MYVECTOR operator -() const;
	bool operator ==(MYVECTOR& x);
	bool operator !=(MYVECTOR& x);
private:
	void Clear();
	int dimension;
	NODE* head;
};

#endif