#include <iostream>

using namespace std;

#include "MYSET.H"

MYSET::MYSET(int size)
{
	elements = new double [size];
	cardinal = 0;
	this->size = size;
}

MYSET::MYSET(const MYSET &x)
{
	this->size = x.cardinal;
	cardinal = x.cardinal;
	elements = new double[this->cardinal];
	for(int i = 0; i < this->cardinal; elements[i ++] = x.elements[i]);
}


MYSET::~MYSET()
{
	delete elements;
}

void MYSET::Append(double x)
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

bool MYSET::IsEmpty()
{
	return (cardinal ? false : true); // (bool) cardinal
}

int MYSET::Cardinal()
{
	return cardinal;
}

void MYSET::Input()
{
	char c;
	double x;
	do
	{
		cin >> x;
		c = getchar();
		if(!Exist(x))
		{
			Append(x);	
		}
	}
	while(c != 10);
}

void MYSET::Output()
{
	int i;
	cout << "{ ";
	for(i = 0; i < cardinal; i ++) 
	{
		if(i != cardinal - 1) cout << elements[i] << ", ";
		else cout << elements[i] << " ";
	}
	cout << "}" << endl;
}

void MYSET::Remove(double x)
{
	int k;
	if(k = Find(x))
	{
		for(; k < size; k ++) elements[k - 1] = elements[k];
		cardinal --;
	}
}

int MYSET::Find(double x)
{
	int position, i = 0;
	if(Exist(x))
	{
		for(; elements[i] != x; i ++);
		position = i + 1;
	}
	else position = 0;
	return position;
}

bool MYSET::Exist(double x)
{
	bool b = false;
	int i;
	for(i = 0; i < cardinal; i ++)
	{
		if(elements[i] == x) b = true;
	}
	return b;
}

double MYSET::Get(int position)
{
	double pos;
	if(position > cardinal || position <= 0) pos = 0,cout << "不正确的引用!\n";
	else pos = elements[position - 1];
	return pos;
}

void MYSET::Clear()
{
	cardinal = 0;
}

double* MYSET::Get()
{
	return elements;
}

MYSET MYSET::Add(MYSET &x)
{
	MYSET y;
	double *p;
	int i;
	p = elements;
	for(i = 0; i < Cardinal(); i ++) y.Append(p[i]);
	p = x.Get();
	for(i = 0; i < x.Cardinal(); i ++) y.Append(p[i]);
	return y;
}

MYSET MYSET::Sub(MYSET &x)
{
	MYSET y;
	double *p;
	int i;
	p = elements;
	for(i = 0; i < Cardinal(); i ++)
	{
		if(!x.Exist(p[i])) y.Append(p[i]);
	}
	return y;
}

MYSET MYSET::Mul(MYSET &x)
{
	MYSET y;
	double *p;
	int i;
	p = elements;
	for(i = 0; i < Cardinal(); i ++)
	{
		if(x.Exist(p[i])) y.Append(p[i]);
	}
	return y;
}

MYSET& MYSET::operator=(const MYSET &x)
{
	this->size = x.cardinal;
	this->cardinal = x.cardinal;
	delete this->elements;
	this->elements = new double[x.cardinal];
	for(int i = 0; i < this->cardinal; this->elements[i++] = x.elements[i]);
	return *this;
}
	
