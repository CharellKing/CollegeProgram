/*-------DOUBLE_LINKLIST.H----------
  此为双向链表:
  数据操作:
  DOUBLE_LINKLIST();//创建双向链表(只有头结点)
  ~DOUBLE_LINKLIST();//delete所有的节点
  DOUBLE_LINKLIST(const DOUBLE_LINKLIST<T>& x);//拷贝构造
  DOUBLE_LINKLIST<T>& operator =(const DOUBLE_LINKLIST<T>& x);//赋值运算
  void Clear();//清掉除头结点以外的所有节点(然后将其连接起来)
  void Append(const T& x, int i);//添加数据x，使其排在顺序的第i个
  void Insert(const T& x);//插入数据x，使数据保持从小到大的顺序
  void Display();//显示所有数据
  void RDisplay();//倒过来显示所有数据
-------------------------------*/
#ifndef _DOUBLE_LINKLIST_H_

#define _DOUBLE_LINKLIST_H_

#include "NODE.H"

template <typename T>
class DOUBLE_LINKLIST
{
public:
	DOUBLE_LINKLIST();
	~DOUBLE_LINKLIST();
	DOUBLE_LINKLIST(const DOUBLE_LINKLIST<T>& x);
	DOUBLE_LINKLIST<T>& operator =(const DOUBLE_LINKLIST<T>& x);
	void Clear();
	void Append(const T& x, int i);
	void Insert(const T& x);
	void Display();
	void RDisplay();
protected:	
	NODE<T>* Node(int i);
	NODE<T>* Before_More_X(const T& x);
	NODE<T>* head;
	int cardinal;
};

template <typename T>
DOUBLE_LINKLIST<T>::DOUBLE_LINKLIST()
{
	head = new NODE<T>();
	head->Prior() = head;
	head->Next() = head;
	cardinal = 0;
}

template <typename T>
DOUBLE_LINKLIST<T>::~DOUBLE_LINKLIST()
{
	NODE<T> *p = head->Next(), *q;
	while(p != head)
	{
		q = p;
		p = p->Next();
		delete [] q;
	}
	delete [] p;
}

template <typename T>
DOUBLE_LINKLIST<T>::DOUBLE_LINKLIST(const DOUBLE_LINKLIST<T>& x)
{
	head = new NODE<T>();
	head->Prior() = head;
	head->Next() = head;
	NODE<T> *p = head, *q = x.head->Next(), *r;
	while(q != x.head)
	{
		r = new NODE<T>(p, p->Next(), q->Data());
		p->Next() = r;
		head->Prior() = r;
		p = p->Next();
		q = q->Next();
	}
	cardinal = x.cardinal;
}

template <typename T>
DOUBLE_LINKLIST<T>& DOUBLE_LINKLIST<T>::operator =(const DOUBLE_LINKLIST<T>& x)
{
	NODE<T> *p, *q, *r;
	if(this != &x)
	{
		Clear();
		p = head, q = x.head->Next();
		while(q != x.head)
		{
			r = new NODE<T>(p, p->Next(), q->Data());
			p->Next() = r;
			head->Prior() = r;
			p = p->Next();
			q = q->Next();
		}
	}
	cardinal = x.cardinal;
	return *this;
}

template <typename T>
void DOUBLE_LINKLIST<T>::Clear()
{
	NODE<T> *p = head->Next(), *q;
	while(p != head)
	{
		q = p;
		p = p->Next();
		delete [] q;
	}
	head->Next() = head;
	head->Prior() = head;
	cardinal = 0;
}

template <typename T>
NODE<T>* DOUBLE_LINKLIST<T>::Node(int n)
{
	NODE<T> *p = head;
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


template <typename T>
void DOUBLE_LINKLIST<T>::Append(const T& x, int n)
{
	NODE<T> *p, *q;
	if(n >= 1 && n <= cardinal + 1)
	{
		p = Node(n - 1);
		q = new NODE<T>(p, p->Next(), x);
		p->Next() = q;
		p = q->Next();
		p->Prior() = q;
		cardinal ++;
	}	
}

template <typename T>
NODE<T>* DOUBLE_LINKLIST<T>::Before_More_X(const T& x)
{
	NODE<T> *p = head->Next();
	while(p != head)
	{
		if(p->Data() > x)
		{
			break;
		}
		p = p->Next();
	}
	return p->Prior();
}

template <typename T>
void DOUBLE_LINKLIST<T>::Insert(const T& x)
{
	NODE<T> *p, *q;
	p = Before_More_X(x);
	q = new NODE<T>(p, p->Next(), x);
	p->Next() = q;
	p = q->Next();
	p->Prior() = q;
	cardinal ++;
}

template <typename T>
void DOUBLE_LINKLIST<T>::Display()
{
	NODE<T> *p = head->Next();
	while(p != head)
	{
		cout << p->Data() << "   ";
		p = p->Next();
	}
}

template <typename T>
void DOUBLE_LINKLIST<T>::RDisplay()
{
	NODE<T> *p = head->Prior();
	while(p != head)
	{
		cout << p->Data() << "   ";
		p = p->Prior();
	}
}
#endif