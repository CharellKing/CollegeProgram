#include <cstdlib>

#include "MYVECTOR.H"

MYVECTOR::MYVECTOR(int dimension) // 创建2维零向量
{
	int i;
	if(dimension <= 1) this->dimension = 2, cout << "不正确的维数!" << endl;
	else this->dimension = dimension;
	head = new NODE;
	NODE *s, *p = head;
	for(i = 0; i < this->dimension; i ++)
	{
		s = new NODE;
		p->Next() = s;
		p = s;
	}
}

MYVECTOR::MYVECTOR(const MYVECTOR& x)
{
	this->dimension = x.dimension;
	head = new NODE;
	NODE *p = head, *q = x.head;
	while(q = q->Next())
	{
		p = p->Next() = new NODE(q->Components());
	}
}

MYVECTOR::~MYVECTOR()
{
	NODE *s;
	while(head)
	{
		s = head;
		head = head->Next();
		delete s;
	}	
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
	NODE *p = x.head;
	x.Clear();
	do
	{
		while(c = in.get(), isspace(c));
		cin.putback(c);
		in >> y;
		if(in)
		{
			i ++;
			p = p->Next() = new NODE(y);
		}
		else
		{
			x.Clear();
			in.clear();
			in.sync();
			cout << "不正确的数据, 请重新输入:";
			i = 0;
			p = x.head;
		}
	}
	while( i < x.dimension);
	return in;
}

void MYVECTOR::Clear()
{
	NODE *s, *p;
	while(head->Next())
	{
		s = head->Next();
		p = s->Next();
		head->Next() = p;
		delete s;
	}	
}

ostream& operator <<(ostream& out, const MYVECTOR& x)
{
	NODE* p = x.head;
	cout << "( ";
	while(p = p->Next())
	{
		cout << p->Components();
		if(p->Next()) cout << ", ";
	}
	cout << " )";
	return out;
}

const MYVECTOR& MYVECTOR::operator =(const MYVECTOR& x)
{
	this->dimension = x.dimension;
	Clear();
	NODE *p = x.head, *q = head;
	while(p = p->Next())
	{
		q = q->Next() = new NODE(p->Components());
	}
	return *this;
}

const MYVECTOR& MYVECTOR::operator =(double x)
{
	NODE *p = head;
	while(p = p->Next())
	{
		p->Components() = x;
	}
	return *this;
}

double& MYVECTOR::operator [](int i)
{
	NODE *p = head;
	if(i <= this->dimension && i > 0)
	{
		for(int j = 0; j < i; j ++, p = p->Next());
		return p->Components();
	}
	else
	{
		cout << "不正确的索引!" << endl;
		exit(1);
	}
}

MYVECTOR& MYVECTOR::operator +=(MYVECTOR& x)
{
	int min;
	if(x.dimension > this->dimension) min = dimension;
	else min = x.dimension;
	for(int i = 1; i <= min; i ++)
	{
		(*this)[i] += x[i];
	}
	if(x.dimension > this->dimension)
	{
		NODE *p = head;
		for(int j = 1; j < i; j ++) p = p->Next();
		for(; i <= x.dimension; i++) p = p->Next() = new NODE(x[i]);
	}
	return *this;
}

MYVECTOR& MYVECTOR::operator -=(MYVECTOR& x)
{
	int min;
	if(x.dimension > this->dimension) min = dimension;
	else min = x.dimension;
	for(int i = 1; i <= min; i ++)
	{
		(*this)[i] -= x[i];
	}
	if(x.dimension > this->dimension)
	{
		NODE *p = head;
		for(int j = 1; j < i; j ++) p = p->Next();
		for(; i <= x.dimension; i++) p = p->Next() = new NODE(-x[i]);
	}
	return *this;
}

MYVECTOR MYVECTOR::operator +(MYVECTOR& x) const
{
	MYVECTOR y(*this);
	if(this->dimension != x.dimension)
	{
		cout << "向量维数不同不能相加!" << endl;
		exit(1);
	}
	else
	{
		y += x;
	}
	return y;
}

MYVECTOR MYVECTOR::operator -(MYVECTOR& x) const
{
	MYVECTOR y(*this);
	if(this->dimension != x.dimension)
	{
		cout << "向量维数不同不能相减!" << endl;
		exit(1);
	}
	else
	{
		
		y -= x;
	}
	return y;

}

double MYVECTOR::operator *(MYVECTOR& x) 
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
		for(i = 1; i <= x.dimension; i ++) sum += x[i] * (*this)[i];
	}
	return sum;
}

MYVECTOR MYVECTOR::operator *(double y) const
{
	int i;
	MYVECTOR z(*this);
	for(i = 1; i <= z.dimension; i ++) z[i] *= y;
	return z;
}

MYVECTOR operator *(double y, const MYVECTOR& x)
{
	return MYVECTOR(x * y);
}

MYVECTOR MYVECTOR::operator -() const
{
	MYVECTOR x(*this);
	for(int i = 1; i <= dimension; i ++) x[i] = -x[i];
	return x;
}

MYVECTOR MYVECTOR::operator +() const
{
	return MYVECTOR(*this);
}

bool MYVECTOR::operator ==(MYVECTOR& x)
{
	if(dimension != x.dimension) return false;
	else
	{
		for(int i = 1; i <= x.dimension; i ++)
		{
			if((*this)[i] != x[i]) return false;
		}
	}
	return true;
}


bool MYVECTOR::operator !=(MYVECTOR& x)
{
	return !(*this == x);
}
