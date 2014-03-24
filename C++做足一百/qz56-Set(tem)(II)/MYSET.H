#ifndef _MYSET_H

#define _MYSET_H

template <class DT>
struct NODE
{
	DT Aelement;
	NODE *next;
};

//template <class DT>
//typedef NODE<DT>* NODE<DT>*;

template <class DT>
class MYSET
{
public:
	MYSET();
	~MYSET(){}
	void Append(DT x);
	bool IsEmpty();
	int Cardinal();
	void Cardinal(int a);
	void Input();
	void Output();
	void Remove(DT x);
	int Find(DT x);
	bool Exist(DT x);
	DT Get(int position);
	NODE<DT>* GetHead();
	MYSET Add(MYSET &x);
	MYSET Sub(MYSET &x);
	MYSET Mul(MYSET &x);
	void Clear();
private:
	NODE<DT>* head;
	int cardinal;
};

template <class DT>
MYSET<DT>::MYSET<DT>()
{
	cardinal = 0;
	head = new NODE<DT>;
	head->next = NULL;
}

template <class DT>
void MYSET<DT>::Append(DT x)
{
	NODE<DT>* s;
	if(!Exist(x))
	{
		s = new NODE<DT>;
		s->next = head->next;
		head->next = s;
		s->Aelement = x;
		cardinal ++;
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
		Append(x);	
	}
	while(c != 10);
}

template <class DT>
void MYSET<DT>::Output()
{
	NODE<DT>* p = head;
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

template <class DT>
void MYSET<DT>::Remove(DT x)
{
	NODE<DT>* p = head, q;
	int k, i;
	if(k = Find(x))
	{
		for(i = 0; i < k; i ++) q = p, p = p->next;
		q->next = p->next;
		delete p;
		cardinal --;
	}
}

template <class DT>
int MYSET<DT>::Find(DT x)
{
	NODE<DT>* p = head->next;
	int position;
	if(Exist(x))
	{
		for(position = 1; p->Aelement != x; p = p->next, position ++);
	}
	else position = 0;
	return position;
}

template <class DT>
bool MYSET<DT>::Exist(DT x)
{
	NODE<DT>* p = head;
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

template <class DT>
DT MYSET<DT>::Get(int position)
{
	NODE<DT>* p = head;
	DT pop;
	int i;
	if(position > cardinal || position <= 0) pop = 0,cout << "不正确的引用!\n";
	else
	{
		for(i = 0; i = position; p = p->next, i ++);
		pop = p->Aelement;
	}
	return pop;
}

template <class DT>
void MYSET<DT>::Clear()
{
	NODE<DT>* p, q;
	while(head->next)
	{
		p = head->next;
		q = p->next;
		head->next = q;
		delete p;
	}
}

template <class DT>
MYSET<DT> MYSET<DT>::Add(MYSET<DT> &x)
{
	MYSET<DT> y;
	NODE<DT>* p = x.GetHead();
	while(p = p->next)
	{
		y.Append(p->Aelement);
	}
	p = head;
	while(p = p->next) 
	{
		if(!x.Exist(p->Aelement)) y.Append(p->Aelement);
	}
	return y;
}

template <class DT>
void MYSET<DT>::Cardinal(int a)
{
	cardinal += a;
}

template <class DT>
MYSET<DT> MYSET<DT>::Sub(MYSET<DT> &x)
{
	MYSET<DT> y;
	NODE<DT>* p = head;
	while(p = p->next)
	{
		if(!x.Exist(p->Aelement)) y.Append(p->Aelement);
	}
	return y;
}

template <class DT>
MYSET<DT> MYSET<DT>::Mul(MYSET<DT> &x)
{
	MYSET<DT> y;
	NODE<DT>* p = x.GetHead();
	while(p = p->next)
	{
		if(Exist(p->Aelement)) y.Append(p->Aelement);
	}
	return y;
}

template <class DT>
NODE<DT>* MYSET<DT>::GetHead()
{
	return head;
}


#endif