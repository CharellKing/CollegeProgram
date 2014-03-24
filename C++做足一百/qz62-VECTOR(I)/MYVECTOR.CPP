#include <cstdlib>

#include "MYVECTOR.H"

MYVECTOR::MYVECTOR(int dimension) // 创建2维零向量
{
	int i;
	if(dimension <= 1) this->dimension = 2, cout << "不正确的维数!" << endl;
	else this->dimension = dimension;
	components = new double[this->dimension];
	for(i = 0; i < this->dimension; i ++) this->components[i] = 0;
}

MYVECTOR::MYVECTOR(const MYVECTOR& x)
{
	this->components = new double [x.dimension];
	this->dimension = x.dimension;
	for(int i = 0; i < x.dimension; i ++) this->components[i] = x.components[i];
}

MYVECTOR::~MYVECTOR()
{
	delete []this->components;
}

int MYVECTOR::Dimension() const// 读取向量维数
{
	return this->dimension;
}

istream& operator >>(istream& in, MYVECTOR& x)
{
	int i = 0;
	double y;
	char c;
	x.Clear();
	do
	{
		while(c = in.get(), isspace(c));
		cin.putback(c);
		in >> y;
		if(in) x.components[i ++] = y;
		else
		{
			x.Clear();
			in.clear();
			in.sync();
			cout << "不正确的数据, 请重新输入:";
			i = 0;
		}
	}
	while( i < x.dimension);
	return in;
}

void MYVECTOR::Clear()
{
	delete []this->components;
	this->components = new double [this->dimension];
}

ostream& operator <<(ostream& out, const MYVECTOR& x)
{
	int i;
	cout << "( ";
	for(i = 0; i < x.dimension - 1; i ++) cout << x.components[i] << ", ";
	cout << x.components[i] << " )";
	return out;
}

const MYVECTOR& MYVECTOR::operator =(const MYVECTOR& x)
{
	this->components = new double [x.dimension];
	this->dimension = x.dimension;
	for(int i = 0; i < x.dimension; i ++) this->components[i] = x.components[i];	
	return *this;
}

const MYVECTOR& MYVECTOR::operator =(double x)
{
	int i;
	for(i = 0; i < this->dimension; i ++) this->components[i] = x;
	return *this;
}

double& MYVECTOR::operator [](int i)
{
	if(i <= this->dimension && i > 0) return this->components[i - 1];
	else
	{
		cout << "不正确的索引!" << endl;
		exit(1);
	}
}

MYVECTOR& MYVECTOR::operator +=(const MYVECTOR& x)
{
	int i;
	if(this->dimension < x.dimension)
	{
		MYVECTOR a(*this);
		delete []components;
		dimension = x.dimension;
		components = new double [dimension];
		for(i = 0; i < a.dimension; i ++) components[i] = a.components[i];
		for(; i < dimension; i ++) components[i] = 0;
	}
	for(i = 0; i < x.dimension; i ++) components[i] += x.components[i];
	return *this;
}

MYVECTOR& MYVECTOR::operator -=(const MYVECTOR& x)
{
	int i;
	if(this->dimension < x.Dimension())
	{
		MYVECTOR a(*this);
		delete []components;
		dimension = x.dimension;
		components = new double [dimension];
		for(i = 0; i < a.dimension; i ++) components[i] = a.components[i];
		for(; i < dimension; i ++) components[i] = 0;
	}
	for(i = 0; i < x.dimension; i ++) components[i] -= x.components[i];
	return *this;
}

MYVECTOR MYVECTOR::operator +(const MYVECTOR& x) const
{
	MYVECTOR y(x);
	/*
	if(this->dimension >= x.Dimension())
	{
		MYVECTOR y(*this);
		y += x;
	}
	else
	{
		MYVECTOR y(x);
		y += (*this);
	}
	return y;
	*/
	if(this->dimension != x.dimension)
	{
		cout << "向量维数不同不能相加!" << endl;
		exit(1);
	}
	else
	{
		y += (*this);
	}
	return y;
}

MYVECTOR MYVECTOR::operator -(const MYVECTOR& x) const
{
	MYVECTOR y(*this);
	/*if(this->dimension >= x.Dimension())
	{
		MYVECTOR y(*this);
		y -= x;
	}
	else
	{
		MYVECTOR y(x);
		y -= (*this);
	}
	return y;
	*/
	if(this->dimension != x.dimension)
	{
		cout << "向量维数不同不能相减!" << endl;
		exit(1);
	}
	else
	{
		
		y -= (x);
	}
	return y;

}

double MYVECTOR::operator *(const MYVECTOR& x) const
{
	double sum = 0;
	int i;
	if(this->dimension != x.dimension)
	{
		cout << "向量维数不同不能相乘!" << endl;
		exit(1);
	}
	else
	{
		for(i = 0; i < x.dimension; i ++) sum += x.components[i] * components[i];
	}
	return sum;
}

MYVECTOR MYVECTOR::operator *(double y) const
{
	int i;
	MYVECTOR z(*this);
	for(i = 0; i < z.dimension; i ++) z.components[i] *= y;
	return z;
}

MYVECTOR operator *(double y, const MYVECTOR& x)
{
	return MYVECTOR(x * y);
}

MYVECTOR MYVECTOR::operator -() const
{
	MYVECTOR x(*this);
	for(int i = 0; i < dimension; i ++) x.components[i] = - x.components[i];
	return x;
}

bool MYVECTOR::operator ==(const MYVECTOR& x) const
{
	if(dimension != x.dimension) return false;
	else
	{
		for(int i = 0; i < x.dimension; i ++)
		{
			if(components[i] != x.components[i]) return false;
		}
	}
	return true;
}


bool MYVECTOR::operator !=(const MYVECTOR& x) const
{
	return !(*this == x);
}
	