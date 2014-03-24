#ifndef _LINKQUEUE_H_

#define _LINKQUEUE_H_

#include "NODE.H"

template <typename T>
class LINKQUEUE
{
public:
	LINKQUEUE();
	~LINKQUEUE();
	LINKQUEUE(const LINKQUEUE<T>& x);
	LINKQUEUE<T>& operator =(const LINKQUEUE<T>& x);
	void Clear();
	void EnQueue(const T& x);
	T DeQueue();
	void Display()const;
	int Length()const;
	NODE<T>* Head()const;
	LINKQUEUE<T> Traverse(T (*Visit) (const T& x))const;
protected:
	NODE<T>* front;
	NODE<T>* rear;
	int length;
};

template <typename T>
LINKQUEUE<T>::LINKQUEUE()
{
	rear = new NODE<T>();
	front = rear;
	length = 0;
}

template <typename T>
LINKQUEUE<T>::~LINKQUEUE()
{
	NODE<T> *p;
	while(rear)
	{
		p = rear;
		rear = rear->Next();
		delete [] p;
	}
}

template <typename T>
LINKQUEUE<T>::LINKQUEUE(const LINKQUEUE<T>& x)
{
	rear = new NODE<T>();
	front = rear;
	NODE<T> *p = x.rear, *q;
	while(p = p->Next())
	{
		q = new NODE<T>(front, front->Next(), p->Data());
		front->Next() = q;
		front = front->Next();
		q = q->Next();
	}
	length = x.length;
}

template <typename T>
LINKQUEUE<T>& LINKQUEUE<T>::operator =(const LINKQUEUE<T>& x)
{
	NODE<T> *p, *q;
	if(this != &x)
	{
		Clear();
		p = x.rear;
		while(p = p->Next())
		{
			q = new NODE<T>(front, front->Next(), p->Data());
			front->Next() = q;
			front = front->Next();
			q = q->Next();
		}
		length = x.length;
	}
	return *this;
}

template <typename T>
void LINKQUEUE<T>::Clear()
{
	NODE<T> *p = rear, *q;
	while(p = p->Next())
	{
		q = p;
		p = p->Next();
		delete [] q;
	}
	rear->Next() = NULL;
	front = rear;
	length = 0;
}

template <typename T>
void LINKQUEUE<T>::EnQueue(const T& x)
{
	NODE<T> *p, *q;
	p = new NODE<T>(rear, rear->Next(), x);
	rear->Next() = p;
	if(length == 0) front = p;
	q = p->Next();
	if(q) q->Prior() = p;
	length ++;
}

template <typename T>
T LINKQUEUE<T>::DeQueue()
{
	NODE<T> *p;
	T data;
	if(length > 0)
	{
		p = front;
		front = front->Prior();
		front->Next() = p->Next();
		data = p->Data();
		length --;
		delete [] p;
		return data;
	}
	else
	{
		throw string("此队列为空，无数据!");
	}
}

template <typename T>
void LINKQUEUE<T>::Display()const
{
	NODE<T> *p = rear;
	while(p = p->Next())
	{
		cout << p->Data() << "   ";
	}
}

template <typename T>
int LINKQUEUE<T>::Length()const
{
	return length;
}

template <typename T>
NODE<T>* LINKQUEUE<T>::Head()const
{
	if(length > 0)
	{
		return front;
	}
	else
	{
		throw string("此队列为空, 无头元素");
	}
}

template <typename T>
LINKQUEUE<T> LINKQUEUE<T>::Traverse(T (*Visit) (const T& x))const
{
	LINKQUEUE<T> other(*this);
	NODE<T>* p = other.rear;
	while(p = p->Next())
	{
		p->Data() = Visit(p->Data());
	}
	return other;
}

#endif