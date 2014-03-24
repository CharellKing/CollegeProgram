#include <iostream>

using namespace std;

#include <cstdlib>

#include "ARRAY_MYSET.H"

ARRAY_MYSET::ARRAY_MYSET(int size)
{
	elements = new double [size];
	this->size = size;
}

ARRAY_MYSET::ARRAY_MYSET(const ARRAY_MYSET &x)
{
	this->size = x.cardinal;
	cardinal = x.cardinal;
	elements = new double[this->cardinal];
	for(int i = 0; i < this->cardinal; elements[i ++] = x.elements[i]);
}


ARRAY_MYSET::~ARRAY_MYSET()
{
	delete elements;
}

void ARRAY_MYSET::Append(double x)
{
	int newsize = size + 10, k;
	if(!Exist(x))
	{
		if(cardinal >= size)
		{
			double *p = elements;
			elements = new double [newsize];
			for (k = 0; k < size; k ++) elements[k] = p[k];
			size = newsize;
			delete p;
		}
		elements[cardinal ++] = x;
	}
	
}

bool ARRAY_MYSET::IsEmpty()const
{
	return (cardinal ? false : true); // (bool) cardinal
}

int ARRAY_MYSET::Cardinal()const
{
	return cardinal;
}

void ARRAY_MYSET::Input()
{
	char c;
	double x;
	do
	{
		while(c = cin.get(), isspace(c) && c != 10);
		if(c != 10)
		{
			cin.putback(c);
			cin >> x;
			if(cin) Append(x);
			else
			{
				Clear();
				cin.clear();
				cin.sync();
				cout << "输入错误,请重新输入!" << endl;
			}
		}
	}
	while(c != 10);
}

void ARRAY_MYSET::Output()const
{
	int i;
	cout << "{ ";
	for(i = 0; i < cardinal; i ++) 
	{
		if(i != cardinal - 1) cout << elements[i] << ", ";
		else cout << elements[i] << " ";
	}
	cout << "}";
}

void ARRAY_MYSET::Remove(double x)
{
	int k;
	if(k = Find(x))
	{
		for(; k < size; k ++) elements[k - 1] = elements[k];
		cardinal --;
	}
}

int ARRAY_MYSET::Find(double x)const
{
	int i;
	for(i = 0; i < cardinal; i ++)
	{
		if(this->elements[i] == x) break;
	}
	if(i == cardinal) return 0;
	return i + 1;
}

bool ARRAY_MYSET::Exist(double x)const
{
	return (Find(x) ? true : false);
}

void ARRAY_MYSET::Clear()
{
	cardinal = 0;
}

void ARRAY_MYSET::Add(const MYSET &x, MYSET &y)const
{
	int i;
	y.Clear();
	for(i = 1; i <= x.Cardinal(); i ++) y.Append(x(i));
	for(i = 1; i <= cardinal; i ++)
	{
		y.Append((*this)(i));
	}
}

void ARRAY_MYSET::Sub(const MYSET &x, MYSET &y)const
{
	int i;
	y.Clear();
	for(i = 1; i <= cardinal; i ++)
	{
		if(!x.Exist((*this)(i))) y.Append((*this)(i));
	}
}

void ARRAY_MYSET::Mul(const MYSET &x, MYSET &y)const
{
	int i;
	y.Clear();
	for(i = 1; i <= cardinal; i ++)
	{
		if(x.Exist((*this)(i))) y.Append((*this)(i));
	}
}

double ARRAY_MYSET::operator()(int i)const
{
	if(i > 0 && i <= cardinal) return elements[i-1];
	else
	{
		exit(1);
		cout << "不正确的引用!" << endl;
	}
}

MYSET& ARRAY_MYSET::operator=(const MYSET &x)
{
	this->size = x.Cardinal();
	this->cardinal = x.Cardinal();
	delete this->elements;
	this->elements = new double[cardinal];
	for(int i = 1; i <= cardinal; i ++) elements[i- 1] = x(i);
	return *this;
}
	
