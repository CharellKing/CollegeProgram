#ifndef _MYSET_H

#define _MYSET_H

template <class DT>

class MYSET
{
public:
	MYSET(int size = 100);
	~MYSET() { }
	void Append(const DT x);
	bool IsEmpty();
	int Cardinal();
	void Input();
	void Output();
	void Remove(const DT x);
	int Find(const DT x);
	bool Exist(const DT x);
	DT Get(int position);
	DT* Get();
	MYSET Add(MYSET<DT> &x);
	MYSET Sub(MYSET<DT> &x);
	MYSET Mul(MYSET<DT> &x);
	void Clear();
private:
	DT *elements;
	int cardinal, size;
};

template <class DT>
MYSET<DT>::MYSET<DT>(int size)
{
	elements = new DT [size];
	cardinal = 0;
	this->size = size;
}

template <class DT>
void MYSET<DT>::Append(const DT x)
{
	int newsize = size + 10, k;
	if(!Exist(x))
	{
		if(cardinal >= size)
		{
			DT *p = elements;
			elements = new DT [newsize];
			for (k = 0; k < size; k ++) elements[k] = p[k];
			size = newsize;
			
			delete p;
		}
		elements[cardinal ++] = x;
	}
	
}

template <class DT>
bool MYSET<DT>::IsEmpty()
{
	return (cardinal ? false : true); // (bool) cardinal
}

template <class DT>
int MYSET<DT>::Cardinal()
{
	return cardinal;
}

template <class DT>
void MYSET<DT>::Input()
{
	char c;
	DT x;
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

template <class DT>
void MYSET<DT>::Output()
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

template <class DT>
void MYSET<DT>::Remove(const DT x)
{
	int k;
	if(k = Find(x))
	{
		for(; k < size; k ++) elements[k - 1] = elements[k];
		cardinal --;
	}
}

template <class DT>
int MYSET<DT>::Find(const DT x)
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

template <class DT>
bool MYSET<DT>::Exist(const DT x)
{
	bool b = false;
	int i;
	for(i = 0; i < cardinal; i ++)
	{
		if(elements[i] == x) b = true;
	}
	return b;
}

template <class DT>
DT MYSET<DT>::Get(int position)
{
	DT pos;
	if(position > cardinal || position <= 0) pos = 0,cout << "不正确的引用!\n";
	else pos = elements[position - 1];
	return pos;
}

template <class DT>
void MYSET<DT>::Clear()
{
	cardinal = 0;
}

template <class DT>
DT* MYSET<DT>::Get()
{
	return elements;
}

template <class DT>
MYSET<DT> MYSET<DT>::Add(MYSET<DT> &x)
{
	MYSET<DT> y;
	DT *p;
	int i;
	p = elements;
	for(i = 0; i < Cardinal(); i ++) y.Append(p[i]);
	p = x.Get();
	for(i = 0; i < x.Cardinal(); i ++) y.Append(p[i]);
	return y;
}

template <class DT>
MYSET<DT> MYSET<DT>::Sub(MYSET<DT> &x)
{
	MYSET<DT> y;
	DT *p;
	int i;
	p = elements;
	for(i = 0; i < Cardinal(); i ++)
	{
		if(!x.Exist(p[i])) y.Append(p[i]);
	}
	return y;
}

template <class DT>
MYSET<DT> MYSET<DT>::Mul(MYSET<DT> &x)
{
	MYSET<DT> y;
	DT *p;
	int i;
	p = elements;
	for(i = 0; i < Cardinal(); i ++)
	{
		if(x.Exist(p[i])) y.Append(p[i]);
	}
	return y;
}
#endif