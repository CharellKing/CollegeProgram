#include <iostream>

using namespace std;

#include "MYSET.H"

MYSET::MYSET()
{
	cardinal = 0;
	head = new NODE;
	head->next = NULL;
}

MYSET::MYSET(const MYSET &x)
{
	head = new NODE;
	head->next = NULL;
	LNODE q = x.head;
	while(q = q->next) Append(q->Aelement);
}
		

MYSET::~MYSET()
{
	LNODE p;
	while(this->head)
	{
		p = head;
		head = head->next;
		delete p;
	}
}

void MYSET::Append(double x)
{
	LNODE s;
	if(!Exist(x))
	{
		s = new NODE;
		s->next = head->next;
		head->next = s;
		s->Aelement = x;
		cardinal ++;
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
		Append(x);	
	}
	while(c != 10);
}

void MYSET::Output()
{
	LNODE p = head;
	int i = 0;
	cout << "{ ";
	while(p = p->next) 
	{
		if(i < cardinal - 1)cout << p->Aelement << ", ";
		else cout << p->Aelement << " ";
		i ++;
	}
	cout << "}" << endl;
}

void MYSET::Remove(double x)
{
	LNODE p = head, q;
	int k, i;
	if(k = Find(x))
	{
		for(i = 0; i < k; i ++) q = p, p = p->next;
		q->next = p->next;
		delete p;
		cardinal --;
	}
}

int MYSET::Find(double x)
{
	LNODE p = head->next;
	int position;
	if(Exist(x))
	{
		for(position = 1; p->Aelement != x; p = p->next, position ++);
	}
	else position = 0;
	return position;
}

bool MYSET::Exist(double x)
{
	LNODE p = head;
	bool b = false;
	while(p = p->next)
	{
		if(p->Aelement == x)
		{
			b = true;
			break;
		}
	}
	return b;
}

double MYSET::Get(int position)
{
	LNODE p = head;
	double pop;
	int i;
	if(position > cardinal || position <= 0) pop = 0,cout << "不正确的引用!\n";
	else
	{
		for(i = 0; i = position; p = p->next, i ++);
		pop = p->Aelement;
	}
	return pop;
}

void MYSET::Clear()
{
	LNODE p;
	while(head->next)
	{
		p = head;
		head = p->next;
		delete p;
	}
}

MYSET MYSET::Add(MYSET &x)
{
	MYSET y;
	LNODE p = x.head;
	while(p = p->next)
	{
		y.Append(p->Aelement);
	}
	p = head;
	while(p = p->next)
	{
		if(!y.Exist(p->Aelement)) y.Append(p->Aelement);
	}
	return y;
}

void MYSET::Cardinal(int a)
{
	cardinal += a;
}

MYSET MYSET::Sub(MYSET &x)
{
	MYSET y;
	LNODE p = head;
	while(p = p->next)
	{
		if(!x.Exist(p->Aelement)) y.Append(p->Aelement);
	}
	return y;
}

MYSET MYSET::Mul(MYSET &x)
{
	MYSET y;
	LNODE p = head;
	while(p = p->next)
	{
		if(x.Exist(p->Aelement)) y.Append(p->Aelement);
	}
	return y;
}

MYSET& MYSET::operator=(const MYSET &x)
{
	LNODE p = x.head;
	this->Clear();
	while(p = p->next) Append(p->Aelement);
	return *this;
}
