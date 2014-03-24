/*--------------LINKLIST.H---------------
  这个头文件定义一个LINKLIST类
  基本操作有:
  LINKLIST():构造函数
  LINKLIST():拷贝构造函数
  LINKLIST& operator = (const LINKLIST& x):赋值运算符重载
  ~LINKLIST():析构各个节点
  Append(const T&x, int i = 1):在链表中插入数据x,使其排在第i位
  Remove(const T&x):删除存在数据x的所有节点
  Remove(UINT i):删除第i各节点
  NODE<T>* Before(int i):返回第i - 1各节点的地址
  T& operator[](int i):调用[]运算符重载，返回第i个节点所携带的数据
  void Display():显示链表中所有节点携带的数据
  void Clear():清除链表中的节点只保留head
  void Insert(const T& x):按从小到大的顺序插入
  NODE* Pre_More_X(const T& x)const;//返回比x大的节点的前一个节点的地址
  LINKLIST PolyAdd(const LINKLIST& x)const;//两多项式求和
  LINKLIST PolySub(const LINKLIST& x)const;//两多项式求差
  LINKLIST PolyMul(const LINKLIST& x)const;//两多项式求积
  double PolySum(NODE<T>* p, int exponent, double value)const;//此多项式求和
  NODE<T>* Head();//返回linklist的头结点
  数据成员有：
  NODE<T>* head:头结点(不装数据)
  size:记录链表中数据的个数
-----------------------------------------*/

#ifndef _LINKLIST_H_

#define _LINKLIST_H_

#include <iostream>

using namespace std;

#include <string>

#include <cmath>

#include "NODE.H"

#include "DEFINITION.H"

#include "MONOMIAL.H"

template <typename T>
class LINKLIST
{
public:
	LINKLIST();
	LINKLIST(const LINKLIST& x);
	LINKLIST& operator = (const LINKLIST& x);
	~LINKLIST();
	void Append(const T& x, int i = 1);
	void Remove(const T&x);
	void Remove(NODE<T>* x);
	void Remove(UINT i);
	NODE<T>* Before(int i);
	T& operator[](int i);
	void Display();
	void Clear();
	void Insert(const T& x);
	void PolyInsert(const T&x);
	NODE<T>* Pre_More_X(const T& x);
	LINKLIST PolyAdd(const LINKLIST& x)const;
	LINKLIST PolySub(const LINKLIST& x)const;
	LINKLIST PolyMul(const LINKLIST& x)const;
	double PolySum(NODE<T>* p, int exponent, double value)const;
	NODE<T>* Head();
private:
	NODE<T>* head;
	UINT size;
};

/**********成员函数的实现*********/

template <typename T>
LINKLIST<T>::LINKLIST()
/*--------------------------------
  将数据的尺寸设为0，new一个头结点
  -------------------------------*/
{
	size = 0;
	head = new NODE<T>();
}

template <typename T>
LINKLIST<T>::LINKLIST(const LINKLIST<T>& x)
/*------------------------------
  将this->size(x.size), 将链表X中的数据加入到this链表中
  且保持数据顺序不变
--------------------------------*/
{
	NODE<T>* p = x.head;
	head = new NODE<T>();
	size = 0;
	while(p = p->Next())
	{
		Append(p->Data(), size + 1);//size确保数据永远加入到链表的末尾
	}
}

template <typename T>
LINKLIST<T>& LINKLIST<T>::operator = (const LINKLIST<T>& x)
/*---------------------------------
  将this->size(x.size), 然后清空链表this，将链表X中的数据加入到this链表中
  且保持数据的顺序不变
-----------------------------------*/

{
	NODE<T>* p = x.head;
	Clear();
	size = 0;
	while(p = p->Next())
	{
		Append(p->Data(), size + 1);//确保数据永远加入到链表的末尾，数据顺序不变
	}
	return *this;
}

template <typename T>
LINKLIST<T>::~LINKLIST()
/*---------------------------------
  delete链表中的所有节点包括head
 --------------------------------*/
{
	NODE<T>* p;
	while(head)
	{
		p = head;
		head = head->Next();
		delete [] p;
	}
}

template <typename T>
void LINKLIST<T>::Append(const T& x, int n)
/*--------------------------------
	将数据X添加到链表顺序的第n个
	前置条件：1 <= n <= size + 1
	后置条件:无
--------------------------------*/
{
	NODE<T> *p, *q;
	q = new NODE<T>(x);//创造一个节点，并将此节点的数据初始化为X
	if(n >= 1 && n <= size + 1)
	{
		p = Before(n);//找到第n-1个节点的地址
		q->Next() = p->Next();
		p->Next() = q;
		size ++;
	}
	else
	{
		throw string("添加失败，不正确的引用!");
	}
}

template <typename T>
void LINKLIST<T>::Remove(const T&x)
/*----------------------------------
	移除所有数据为X的节点
----------------------------------*/
{
	NODE<T> *p = head, *q;
	while(q = p->Next())
	{
		if(q->Data() == x)
		{
			p->Next() = q->Next();
			delete [] q;
			size --;
		}
		else
		{
			p = p->Next();
		}
	}
}

template <typename T>
void LINKLIST<T>::Remove(NODE<T>* x)
{
	NODE<T> *p = head, *q;
	while(q = p->Next())
	{
		if(x == q)
		{
			break;
		}
		else
		{
			p = p->Next();
		}
	}
	if(q)
	{
		p->Next() = q->Next();
		delete [] q;
	}
}

template <typename T>
void LINKLIST<T>::Remove(UINT i)
/*-------------------------------
  移除第i个节点
  前置条件: 1 <= i <= size
 ------------------------------*/
{
	NODE<T> *p, *q;
	p = Before(i);//找到第i- 1个节点的地址
	q = p->Next();
	p->Next() = q->Next();
	size --;
	delete [] q;
}

template <typename T>
NODE<T>* LINKLIST<T>::Before(int n)
/*------------------------------
找到第n - 1的节点的地址
前置条件: 1 <= i <= size + 1
--------------------------------*/
{
	NODE<T>* p = head;
	UINT i;
	if(n >= 1 && n <= size + 1)
	{
		for(i = 1; i < n; i ++)
		{
			p = p->Next();
		}
	}
	else
	{
		throw string("不正确的参数引用!");//抛出异常
	}
	return p;
}

template <typename T>
T& LINKLIST<T>::operator[](int n)
/*------------------------------
	返回第i个节点所携带的数据
	并且可以修改此数据
	前置条件: 1 <= i <= size
	后置条件:返回NODE[n]->data
------------------------------*/
{
	NODE<T>* p = head;
	UINT i;
	if(n >= 1 && n <= size)
	{
		for(i = 0; i < n; i ++)
		{
			p = p->Next();
		}
	}
	else
	{
		throw string("不正确的引用!");
	}
	return p->Data();
}

template <typename T>
void LINKLIST<T>::Display()
/*---------------------------
  显示所有节点所携带的数据
-----------------------------*/
{
	NODE<T>* p = head;
	while(p = p->Next())
	{
		cout << p->Data() << "    ";
	}
}

template <typename T>
void LINKLIST<T>::Clear()
/*-----------------------
  清除所有节点(除了头结点)
-------------------------*/
{
	NODE<T>* p = head;
	while(head->Next())
	{
		p = head->Next();
		head->Next() = p->Next();
		delete [] p;
	}
}


	
template<typename T>
void LINKLIST<T>::Insert(const T& x)
/*-----------------------
按从大到小的顺序插入数据
-------------------------*/
{
	NODE<T> *p = head, *q;
	p = Pre_More_X(x);
	q = new NODE<T>;
	q->Data() = x;
	q->Next() = p->Next();
	p->Next() = q;
}

template <typename T>
NODE<T>* LINKLIST<T>::Pre_More_X(const T& x)
/*-----------------------------------
  返回比x大的前一个节点的地址
------------------------------------*/
{
	NODE<T> *p = head, *q;
	while(q = p->Next())
	{
		if(q->Data() > x)
		{
			break;
		}
		else
		{
			p = p->Next();
		}
	}
	return p;
}

template<typename T>
void LINKLIST<T>::PolyInsert(const T& x)
/*-----------------------
按从大到小的顺序插入数据,针对多项式
-------------------------*/
{
	NODE<T> *p = head, *q;
	T b;
	if(x.Coefficient())//系数不为0才插入
	{
		p = Pre_More_X(x);//返回比x大的前一个节点的地址
		b = p->Data();
		if(p->Data() == x && b.Coefficient())//防止其和头节点匹配
		{
			b.Coefficient(b.Coefficient() + x.Coefficient());
			if(b.Coefficient()) p->Data() = b;
			else Remove(p);
		}
		else
		{
			q = new NODE<T>;
			q->Data() = x;
			q->Next() = p->Next();
			p->Next() = q;
		}
	}
}

template <typename T>
LINKLIST<T> LINKLIST<T>::PolyAdd(const LINKLIST<T>& x)const
/*-------------------------------------
  两多项式相加
 -------------------------------------*/
{
	NODE<T> *p = head->Next(), *q = x.head->Next();
	T a;
	LINKLIST<T> llist;
	do
	{
		if(p != NULL && q != NULL)
		{
			if(p->Data() > q->Data())
			{
				a = q->Data();
				llist.PolyInsert(a);
				q = q->Next();
			}
			else if(p->Data() < q->Data())
			{
				a = p->Data();
				llist.PolyInsert(a);
				p = p->Next();
			}
			else
			{
				a = p->Data() + q->Data();
				llist.PolyInsert(a);
				p = p->Next();
				q = q->Next();
			}
		}
		else if(q != NULL && p == NULL)
		{
			a = q->Data();
			llist.PolyInsert(a);
			q = q->Next();
		}
		else if(q == NULL && p != NULL)
		{
			a = p->Data();
			llist.PolyInsert(a);
			p = p->Next();
		}
	}
	while(p != NULL || q != NULL);
	return llist;
	
}

template <typename T>
LINKLIST<T> LINKLIST<T>::PolySub(const LINKLIST<T>& x)const
/*---------------------------
	两多项式相减
---------------------------*/
{
	NODE<T> *p = head->Next(), *q = x.head->Next();
	T a;
	LINKLIST<T> llist;
	do
	{
		if(p != NULL && q != NULL)//两链表每匹配完
		{
			if(p->Data() > q->Data())//如果此时q数据指数小于p的数据指数
			{
				a = - q->Data();
				llist.PolyInsert(a);
				q = q->Next();
			}
			else if(p->Data() < q->Data())//如果此时q数据指数大于p的数据指数
			{
				a = p->Data();
				llist.PolyInsert(a);
				p = p->Next();
			}
			else//如果p的数据指数等于q的数据指数
			{
				a = p->Data() - q->Data();
				llist.PolyInsert(a);
				p = p->Next();
				q = q->Next();
			}
		}
		else if(q != NULL && p == NULL)//p匹配完了，q未匹配完
		{
			a = - q->Data();
			llist.PolyInsert(a);
			q = q->Next();
		}
		else if(q == NULL && p != NULL)//q匹配完了，p未匹配完
		{
			a = p->Data();
			llist.PolyInsert(a);
			p = p->Next();
		}
	}
	while(p != NULL || q != NULL);//如果pq都匹配完了，结束
	return llist;
}

template <typename T>
LINKLIST<T> LINKLIST<T>::PolyMul(const LINKLIST<T>& x)const
/*------------------------------
	两多项式想乘
-----------------------------*/
{
	NODE<T> *p = x.head, *q;
	LINKLIST<T> llist;
	while(p = p->Next())
	{
		q = head;
		while(q = q->Next())
		{
			llist.PolyInsert(p->Data() * q->Data());
		}
	}
	return llist;
}

template <typename T>
double LINKLIST<T>::PolySum(NODE<T>* p, int exponent, double value)const
/*----------------------------
  利用递归求和
  例如：2x(5) + 10x(15) + 3x(40) + x(50) + 2x(98)
  化为：x(5)(2 + x(15 -5 )(10 + x(40 - 15)(3 + x(50 - 40)(1 + 2x(98 - 50)))))
  如此递归。
 -----------------------------*/
{
	T a;
	a = p->Data();
	if(!p->Next())
	{
		return a.Coefficient() * pow(value, a.Exponent() - exponent);
	} 
	else
	{
		return (a.Coefficient() + PolySum(p->Next(), a.Exponent(), value))
				* pow(value, (a.Exponent() - exponent));
	}
}


template<typename T>
NODE<T>* LINKLIST<T>::Head()
//返回头结点的地址
{
	return head;
}

#endif