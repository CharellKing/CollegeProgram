#ifndef _Sparse_h_

#define _Sparse_h_

#include <string>

#include "TupNode.h"

const UINT INIT_SIZE = 30;

const UINT INCREASEMENT = 10;

template <typename T>
class Sparse
{
public:
	Sparse(int sum_row = 1, int sum_column = 1, int size = INIT_SIZE);
	~Sparse();
	Sparse(const Sparse<T>& x);
	const Sparse<T>& operator =(const Sparse<T>& x);
	void Input();
	void Append(const TupNode<T>& x);
	void Output()const;
	void Display()const;
	Sparse<T> Transpose()const;
	Sparse<T> Add(const Sparse<T>& x)const;
	Sparse<T> Sub(const Sparse<T>& x)const;
	Sparse<T> Mul(const Sparse<T>& x)const;
	static int PosPrior(const TupNode<T>& x, const TupNode<T>& y); 
private:
	UINT sum_column, sum_row, size, length;
	TupNode<T>* elements;
};

template <typename T>
Sparse<T>::Sparse(int sum_row, int sum_column, int size)
{
	if(sum_column <= 0) sum_column = 1;
	if(sum_row <= 0) sum_row = 1;
	if(size <= 0) size = INIT_SIZE;
	this->size = size;
	elements = new TupNode<T>[size];
	this->sum_column = sum_column;
	this->sum_row = sum_row;
	length = 0;
}

template <typename T>
Sparse<T>::~Sparse()
{
	delete [] elements;
}

template <typename T>
Sparse<T>::Sparse(const Sparse<T>& x)
{
	int i;
	sum_column = x.sum_column;
	sum_row = x.sum_row;
	size = x.size;
	length = x.length;
	elements = new TupNode<T>[size];
	for(i = 0; i < length; i ++)
	{
		elements[i] = x.elements[i];
	}
}

template <typename T>
const Sparse<T>& Sparse<T>::operator =(const Sparse<T>& x)
{
	int i;
	if(this != &x)
	{
		sum_column = x.sum_column;
		sum_row = x.sum_row;
		size = x.size;
		length = x.length;
		delete [] elements;
		elements = new TupNode<T>[size];
		for(i = 0; i < length; i ++)
		{
			elements[i] = x.elements[i];
		}
	}
	return *this;
}

template <typename T>
void Sparse<T>::Input()
{
	int i, j;
	TupNode<T> a;
	T x;
	for(i = 1; i <= sum_row; i ++)
	{
		for(j = 1; j <= sum_column; j ++)
		{
			cin >> x;
			if(x != 0)
			{
				a.Row(i);
				a.Column(j);
				a.Data(x);
				Append(a);
			}
		}
	}
	cin.sync();
}

template <typename T>
void Sparse<T>::Append(const TupNode<T>& x)
{
	TupNode<T>* elements;
	int i;
	if(length == size)
	{
		elements = new TupNode<T>[length];
		for(i = 0; i < length; i ++)
		{
			elements[i] = this->elements[i];
		}
		delete [] this->elements;
		size += INCREASEMENT;
		this->elements = new TupNode<T>[size];
		for(i = 0; i < length; i ++)
		{
			this->elements[i] = elements[i];
		}
		delete [] elements;
	}
	this->elements[length] = x;
	length ++;
}

template <typename T>
void Sparse<T>::Output()const
{
	int i, j, k = 0;
	for(i = 1; i <= sum_row; i ++)
	{
		for(j = 1; j <= sum_column; j ++)
		{
			if(k < length && elements[k].Row() == i && elements[k].Column() == j)
			{
				cout << elements[k].Data() << ' ';
				k ++;
			}
			else
			{
				cout << "0 ";
			}
		}
		cout << endl;
	}
}

template <typename T>
void Sparse<T>::Display()const
{
	int i;
	for(i = 0; i < length; i ++)
	{
		cout << "< " << elements[i].Row() << ", " << elements[i].Column() << ", " << elements[i].Data() << " > ";
	}
}

template <typename T>
Sparse<T> Sparse<T>::Transpose()const
{
	int i, j, k = 0;
	Sparse<T> a(sum_column, sum_row, size);
	a.length = length;
	for(i = 1; i <= sum_column && k != length ; i ++)
	{
		for(j = 0; j < length; j ++)
		{
			if(elements[j].Column() == i)
			{
				a.elements[k].Row(elements[j].Column());
				a.elements[k].Column(elements[j].Row());
				a.elements[k].Data(elements[j].Data());
				k ++;
			}
		}
	}
	return a;
}



template <typename T>
Sparse<T> Sparse<T>::Add(const Sparse<T>& x)const
{
	int x_start, t_start, k;
	T sum;
	TupNode<T> b;
	Sparse<T> a(x.sum_row, x.sum_column, x.size + length);
	if(x.sum_row == sum_row && x.sum_column == sum_column)
	{
		for(x_start = 0, t_start = 0; x_start < x.length && t_start < length;)
		{
			k = PosPrior(elements[t_start], x.elements[x_start]);
			if(k > 0)
			{
				a.Append(x.elements[x_start]);
				x_start ++;
			}
			else if(k < 0)
			{
				a.Append(elements[t_start]);
				t_start ++;
			}
			else
			{
				sum = x.elements[x_start].Data() + elements[t_start].Data();
				if(sum != 0)
				{
					b.Row(x.elements[x_start].Row());
					b.Column(x.elements[x_start].Column());
					b.Data(sum);
					a.Append(b);
				}
				x_start ++;
				t_start ++;
			}
		}
	
		if(x_start < x.length)
		{
			for(; x_start < x.length; x_start ++)
			{
				a.Append(x.elements[x_start]);
			}
		}
		else if(t_start < length)
		{
			for(; t_start < length; t_start ++)
			{
				a.Append(elements[t_start]);
			}
		}
	}
	else
	{
		throw string("两矩阵不能相加!");
	}
	return a;
}


template <typename T>
Sparse<T> Sparse<T>::Sub(const Sparse<T>& x)const
{
	int x_start, t_start, k;
	T sum;
	TupNode<T> b;
	Sparse<T> a(x.sum_row, x.sum_column, x.size + length);
	if(x.sum_row == sum_row && x.sum_column == sum_column)
	{
		for(x_start = 0, t_start = 0; x_start < x.length && t_start < length;)
		{
			k = PosPrior(elements[t_start], x.elements[x_start]);
			if(k > 0)
			{
				x.elements[x_start].Data_negate();
				a.Append(x.elements[x_start]);
				x_start ++;
			}
			else if(k < 0)
			{
				a.Append(elements[t_start]);
				t_start ++;
			}
			else
			{
				sum = elements[t_start].Data() - x.elements[x_start].Data();
				if(sum != 0)
				{
					b.Row(x.elements[x_start].Row());
					b.Column(x.elements[x_start].Column());
					b.Data(sum);
					a.Append(b);
				}
				x_start ++;
				t_start ++;
			}
		}
	
		if(x_start < x.length)
		{
			for(; x_start < x.length; x_start ++)
			{
				x.elements[x_start].Data_negate();
				a.Append(x.elements[x_start]);
			}
		}
		else if(t_start < length)
		{
			for(; t_start < length; t_start ++)
			{
				a.Append(elements[t_start]);
			}
		}
	}
	else
	{
		throw string("两矩阵不能相减!");
	}
	return a;
}



template <typename T>
Sparse<T> Sparse<T>::Mul(const Sparse<T>& x)const
{
	Sparse<T> a(sum_row, x.sum_column);
    Sparse<T> b(x.sum_column, x.sum_row, x.length);
	TupNode<T> c;
	int row = 1, column = 1, b_start, t_start, orginal = 0;
	T sum;
	if(sum_row == x.sum_column && sum_column == x.sum_row)
	{
		b = x.Transpose();
		do
		{
			b_start = 0;
			while(b_start < b.length)
			{
				t_start = orginal;
				sum = 0;
				//this的第row行和b的第column列相乘
				while(elements[t_start].Row() == row 
					  && b.elements[b_start].Row() == column)
				{
					if(elements[t_start].Column() > b.elements[b_start].Column())
					{
						b_start ++;
					}
					else if(elements[t_start].Column() < b.elements[b_start].Column())
					{
						t_start ++;
					}
					else
					{
						sum += (elements[t_start].Data() * b.elements[b_start].Data());
						b_start ++;
						t_start ++;
					}
				}
				if(sum != 0)
				{
					c.Data(sum);
					c.Row(row);
					c.Column(column);
					a.Append(c);
				}
				column ++;
				while(b.elements[b_start].Row() < column && b_start < b.length)
				{
					b_start ++;
				}
				if(column > a.sum_column)
				{
					column = 1;
					row ++;
				}
			}
			while(elements[t_start].Row() < row && row < length)
			{
				t_start ++;
			}
			orginal = t_start;
		}
		while(t_start < length);
	}
	else
	{
		throw string("两矩阵不能相乘!");
	}
	return a;
}

template <typename T>
int Sparse<T>::PosPrior(const TupNode<T>& x, const TupNode<T>& y)
{
	int result;
	if(x.Row() > y.Row())
	{
		result = 1;
	}
	else if(x.Row() < y.Row())
	{
		result = -1;
	}
	else if(x.Column() > y.Column())
	{
		result = 1;
	}
	else if(x.Column() < y.Column())
	{
		result = -1;
	}
	else
	{
		result = 0;
	}
	return result;
}

#endif