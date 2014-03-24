/*---------C_LINKLIST.H---------------
	此为循环链表;
	操作函数:
	C_LINKLIST();//构造函数，创造一个尾节点
	~C_LINKLIST();//析构函数，删除所有节点
	C_LINKLIST(const C_LINKLIST<T>& x);//拷贝构造函数
	C_LINKLIST<T>& operator =(const C_LINKLIST<T>& x);//赋值运算
	void Display();//显示所有数据
	void Append(const T& x, int i = 1);//将数据x插入到第i个数(i默认为1)
	void Insert(const T& x);//将数据x插入数据，使数据保持从大到小的顺序
	int Cardinal();//返回数据的个数
	NODE<T>* Node(int n = 1);//返回第i个节点的地址
	NODE<T>* Before_More_X(const T& x);//返回大于x的数据所在节点的前一个节点的地址
	void Clear();//删除所有的节点(除了尾节点以外);
	T& Element(int n);//得到第n个数据，并可以修改它
	void DeleteLast();//删除最后一个数据的节点
---------------------------------------*/
#ifndef _C_LINKLIST_H_

#define _C_LINKLIST_H_

#include <string>

#include "DEFINITION.H"

#include "NODE.H"

template <typename T>
class C_LINKLIST
{
public:
	C_LINKLIST();
	~C_LINKLIST();
	C_LINKLIST(const C_LINKLIST<T>& x);
	C_LINKLIST<T>& operator =(const C_LINKLIST<T>& x);
	void Display();
	void Append(const T& x, int i = 1);
	void Insert(const T& x);
	int Cardinal();
	void Clear();
	T& Element(int n);
	void DeleteLast();
protected:
	NODE<T>* Node(int n = 1);
	NODE<T>* Before_More_X(const T& x);
	NODE<T>* tail;
	int cardinal;
};

template <typename T>
C_LINKLIST<T>::C_LINKLIST()
{
	cardinal = 0;
	tail = new NODE<T>();
	tail->Next() = tail;
}

template <typename T>
C_LINKLIST<T>::~C_LINKLIST()
{
	NODE<T> *p = tail->Next(), *q;
	while(p != tail)
	{
		q = p;
		p = p->Next();
		delete [] q;
	}
	delete [] tail;
}

template <typename T>
C_LINKLIST<T>::C_LINKLIST<T>(const C_LINKLIST<T>& x)
{
	tail = new NODE<T>();
	tail->Next() = tail;
	NODE<T> *p = x.tail->Next(), *q = tail, *r;
	while(p != x.tail)
	{
		r = new NODE<T>(p->Data(), q->Next());
		q->Next() = r;
		p = p->Next();
		q = q->Next();
	}
	cardinal = x.cardinal;
}

template <typename T>
C_LINKLIST<T>& C_LINKLIST<T>::operator =(const C_LINKLIST<T>& x)
{
	if(this != &x)
	{
		Clear();
		NODE<T> *p = x.tail->Next(), *q = tail, *r;
		while(p != x.tail)
		{
			r = new NODE<T>(p->Data(), q->Next());
			q->Next() = r;
			p = p->Next();
			q = q->Next();
		}
		cardinal = x.cardinal;
	}
	return *this;
}

template <typename T>
void C_LINKLIST<T>::Display()
{
	NODE<T>* p = tail->Next();
	while(p != tail)
	{
		cout << p->Data() << "   ";
		p = p->Next();
	}
}

template <typename T>
NODE<T>* C_LINKLIST<T>::Node(int n)
{
	NODE<T>* p = tail;
	int i;
	if(n >= 0 && n <= cardinal)
	{
		for(i = 0; i < n; i ++)
		{
			p = p->Next();
		}
	}
	else
	{
		throw string("不正确的参数!");
	}
	return p;
}

template<typename T>
void C_LINKLIST<T>::Append(const T& x, int n)
{
	NODE<T> *p, *q;
	if(n >= 1 && n <= cardinal + 1)
	{
		p = Node(n - 1);
		q = new NODE<T>(x, p->Next());
		p->Next() = q;
		cardinal ++;
	}	
}

template <typename T>
NODE<T>* C_LINKLIST<T>::Before_More_X(const T& x)
{
	NODE<T> *p = tail, *q;
	while((q = p->Next()) != tail)
	{
		if(q->Data() > x)
		{
			break;
		}
		p = p->Next();
	}
	return p;
}

		

template<typename T>
void C_LINKLIST<T>::Insert(const T& x)
{
	NODE<T> *p = Before_More_X(x), *q;
	q = new NODE<T>(x, p->Next());
	p->Next() = q;
	cardinal ++;
}

template <typename T>
int C_LINKLIST<T>::Cardinal()
{
	return cardinal;
}

template <typename T>
void C_LINKLIST<T>::Clear()
{
	NODE<T> *p = tail->Next(), *q;
	while(p != tail)
	{
		q = p;
		p = p->Next();
		delete [] q;
	}
	tail->Next() = p;
}

template <typename T>
T& C_LINKLIST<T>::Element(int n)
{
    NODE<T>* p;
    if(n >= 1 && n <= cardinal)
    {
         p = Node(n);
         return p->Data();
    }
    else
    {
        throw string("不正确的参数!");
    }
}

template <typename T>
void C_LINKLIST<T>::DeleteLast()
{
     NODE<T> *p, *q;
     p = Node(cardinal - 1);
     q = p->Next();
     p->Next() = q->Next();
     delete [] q;
	 cardinal --;
}
     
         

#endif
