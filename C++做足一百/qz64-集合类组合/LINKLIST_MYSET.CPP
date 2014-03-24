#include <iostream>

using namespace std;

#include <cstdlib>

#include "LINKLIST_MYSET.H"

LINKLIST_MYSET::LINKLIST_MYSET()
{
	cardinal = 0;
	head = new NODE;
	head->next = NULL;
}

LINKLIST_MYSET::LINKLIST_MYSET(const LINKLIST_MYSET &x)
{
	head = new NODE;
	head->next = NULL;
	LNODE q = x.head;
	while(q = q->next) Append(q->Aelement);
}
		

LINKLIST_MYSET::~LINKLIST_MYSET()
{
	LNODE p;
	while(this->head)
	{
		p = head;
		head = head->next;
		delete p;
	}
}

void LINKLIST_MYSET::Append(double x)
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

bool LINKLIST_MYSET::IsEmpty()const
{
	return (cardinal ? false : true); // (bool) cardinal
}

int LINKLIST_MYSET::Cardinal()const
{
	return cardinal;
}

void LINKLIST_MYSET::Input()
{
	char c;
	double x;
	do
	{
		while(cin.get(c),  isspace(c) && c != 10);
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

void LINKLIST_MYSET::Output()const
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
	cout << "}";
}

void LINKLIST_MYSET::Remove(double x)
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

int LINKLIST_MYSET::Find(double x)const
{
	LNODE p = head;
	for(int i = 0; i < cardinal; i ++)
	{
		p = p->next;
		if(p->Aelement == x) break;
	}
	if(i == cardinal) return 0;
	else return i + 1;
}

bool LINKLIST_MYSET::Exist(double x)const
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

void LINKLIST_MYSET::Clear()
{
	LNODE p, s;
	while(head->next)
	{
		s = p = head->next;
		head->next = p->next;
		delete s;
	}
	cardinal = 0;
}

void LINKLIST_MYSET::Add(const MYSET &x, MYSET &y)const
{
	int i;
	y.Clear();
	for(i = 1; i <= cardinal; i ++)
	{
		y.Append((*this)(i));
	}
	for(i = 1; i <= x.Cardinal(); i ++)
	{
		y.Append(x(i));
	}
}

void LINKLIST_MYSET::Cardinal(int a)
{
	cardinal += a;
}

void LINKLIST_MYSET::Sub(const MYSET &x, MYSET &y)const
{
	int i;
	y.Clear();
	for(i = 1; i <= cardinal; i ++)
	{
		if(!x.Exist((*this)(i))) y.Append((*this)(i));
	}
}

void LINKLIST_MYSET::Mul(const MYSET &x, MYSET &y)const
{
	int i;
	y.Clear();
	for(i = 1; i <= cardinal; i ++)
	{
		if(x.Exist((*this)(i))) y.Append((*this)(i));
	}
}

double LINKLIST_MYSET::operator()(int i)const
{
	NODE *p = this->head;
	if(i > 0 && i <= cardinal)
	{
		for(int j = 0; j < i; j ++)
		{
			p = p->next;
		}
	}
	else
	{
		cout << "不正确的引用!" << endl;
		exit(1);
	}
	return p->Aelement;
}

MYSET& LINKLIST_MYSET::operator=(const MYSET &x)
{
	this->Clear();
	for(int i = 1; i <= x.Cardinal(); i ++) Append(x(i));
	return *this;
}
