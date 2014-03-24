#ifndef _LINKLIST_H_

#define _LINKLIST_H_

#include "NODE.H"

template <typename T>
class LINKLIST
{
public:
	LINKLIST();
	~LINKLIST();
	void Output();
	void Insert(const T& x, const T& y);
	void Remove(const T& x);
	void Clear();
	int Cardinal();
	NODE<T>* Before_X(const T&x)const;
protected:
	NODE<T> *head;
	int cardinal;
};

template <typename T>
void LINKLIST<T>::Output()
{
	NODE<T> *p = head;
	while(p = p->Next())
	{
		cout << p->Data() << "   ";
	}
}

template <typename T>
LINKLIST<T>::LINKLIST()
{
	cardinal = 0;
	head = new NODE<T>();
}


template <typename T>
LINKLIST<T>::~LINKLIST()
{
	NODE<T> *p;
	while(head)
	{
		p = head;
		head = head->Next();
		delete [] p;
	}
}

template <typename T>
NODE<T>* LINKLIST<T>::Before_X(const T&x)const
{
	NODE<T> *p = head, *q;
	while(q = p->Next())
	{
		if(q->Data() == x)
		{
			break;
		}
		p = p->Next();
	}
	return p;
}

template <typename T>
void LINKLIST<T>::Insert(const T& x, const T& y)
{
	NODE<T> *p, *q;
	p = new NODE<T>();
	p->Data() = y;
	q = Before_X(x);
	p->Next() = q->Next();
	q->Next() = p;
	cardinal ++;
}


template <typename T>
void LINKLIST<T>::Remove(const T& x)
{
	NODE<T> *p = head, *q;
	while(q = p->Next())
	{
		if(q->Data() == x)
		{
			p->Next() = q->Next();
			delete [] q;
			cardinal --;
		}
		else
		{
			p = p->Next();
		}
	}
}



template <typename T>
void LINKLIST<T>::Clear()
{
	NODE<T> *p = head;
	while(head->Next())
	{
		p = head->Next();
		head->Next() = p->Next();
		delete [] p;
	}
	cardinal = 0;
}


template <typename T>
int LINKLIST<T>::Cardinal()
{
	return cardinal;
}
 


#endif