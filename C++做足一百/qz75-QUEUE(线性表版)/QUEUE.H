#ifndef _QUEUE_H_

#define _QUEUE_H_

#include <string>

const int QUEUE_INIT_SIZE = 20;

const int QUEUE_INCREMENT = 30;

template <typename T>
class QUEUE
{
public:
	QUEUE();
	~QUEUE();
	QUEUE(const QUEUE<T>& x);
	const QUEUE<T>& operator =(const QUEUE<T>& x);
	void Clear();
	bool IsEmpty()const;
	int Length()const;
	T& Top();
	void EnQueue(const T& x);
	const T& DeQueue();
	QUEUE<T> Traverse(T (*Visit)(const T& x))const;
	T operator[](int i)const;
	bool IsExist(const T& x)const;
	void Display()const;
	
private:
	T *base, *top;
	int queuesize, length;
};

template <typename T>
QUEUE<T>::QUEUE()
{
	queuesize = QUEUE_INIT_SIZE;
	length = 0;
	base = new T[queuesize];
	top = base;
}

template <typename T>
QUEUE<T>::~QUEUE()
{
	delete [] base;
}

template <typename T>
QUEUE<T>::QUEUE(const QUEUE<T>& x)
{
	int i;
	queuesize = x.queuesize;
	length = x.length;
	base = new T[queuesize];
	for(i = 0; i < length; i ++)
	{
		base[i] = x.base[i];
	}
	top = base + length;
}

template <typename T>
const QUEUE<T>& QUEUE<T>::operator =(const QUEUE<T>& x)
{
	int i;
	if(this != &x)
	{
		delete [] base;
		queuesize = x.queuesize;
		length = x.length;
		base = new T [queuesize];
		for(i = 0; i < length; i ++)
		{
			base[i] = x.base[i];
		}
		top = base + length;
	}
	return *this;
}

template <typename T>
void QUEUE<T>::Clear()
{
	length = 0;
	top = base;
}


template <typename T>
bool QUEUE<T>::IsEmpty()const
{
	return length == 0;
}

template <typename T>
int QUEUE<T>::Length()const
{
	return length;
}

template <typename T>
T& QUEUE<T>::Top()
{
	if(length > 0)
	{
		return *(top - 1);
	}
	else
	{
		throw string("此栈为空,无数据!");
	}
}

template <typename T>
void QUEUE<T>::EnQueue(const T& x)
{
	T *p, *q = base;
	int i;
	if(length >= queuesize)
	{
		p = new T[length];
		for(i = 0; i < length; i ++)
		{
			p[i] = base[i];
		}
		delete [] base;
		queuesize += QUEUE_INCREMENT;
		base = new T[queuesize];
		for(i = 0; i < length; i ++)
		{
			base[i + 1] = p[i];
		}
		delete [] p;
	}
	else
	{
		for(i = length - 1; i >= 0; i --)
		{
			base[i + 1] = base[i];
		}
	}
	*base = x;
	length ++;
	top = base + length;
}

template <typename T>
const T& QUEUE<T>::DeQueue()
{
	if(length > 0)
	{
		length --;
		return *(--top);
	}
	else
	{
		throw string("此栈为空，不能再删除数据!");
	}
} 

template <typename T>
QUEUE<T> QUEUE<T>::Traverse(T (*Visit)(const T& x))const
{
	QUEUE<T> other(*this);
	T* p = other.base;
	for(; p != other.top; p ++)
	{
		*p = Visit(*p);
	}
	return other;
}

template <typename T>
T QUEUE<T>::operator[](int n)const
{
	if(n >= 1 && n <= length)
	{
		return base[n - 1];
	}
	else
	{
		throw string("引用的参数错误!");
	}
}

template <typename T>
bool QUEUE<T>::IsExist(const T& x)const
{
	int i;
	for(i = 0; i < length; i ++)
	{
		if(x == base[i])
		{
			return true;
		}
	}
	return false;
}
		
template <typename T>
void QUEUE<T>::Display()const
{
	T* p = base;
	for(; p != top; p ++)
	{
		cout << *p << ' ';
	}
}


#endif