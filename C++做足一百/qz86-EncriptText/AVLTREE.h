#ifndef _AVLTREE_H_

#define _AVLTREE_H_

#include "AVL_NODE.H"

typedef unsigned UINT;

const bool left_insert = true;

const bool right_insert = false;

template <typename T>
class AVLTREE
{
public:
	AVLTREE();
	~AVLTREE();
	AVLTREE(const AVLTREE<T>& x);
	const AVLTREE<T>& operator =(const AVLTREE<T>& x);
	void Insert(const T& x, int (*Compare)(const T& x, const T& y));
	AVLNODE<T>* SetInsert(const T& x, int (*Compare)(const T& x, const T& y));
	void GetData(T**& elems);
	int DataNumber()const;
	void Find(T& target, int (*Compare)(const T& x, const T& y))const;
	void Display()const;
protected:
	static void Display(const AVLNODE<T>* root);
	static void Destroy(AVLNODE<T>*& p);
	static void Copy(AVLNODE<T>*& root_receive, const AVLNODE<T>* root_give);
	static void Insert(AVLNODE<T>*& root, const T& elem, bool& insert_side, int (*Compare)(const T& x, const T& y));
	static AVLNODE<T>* Insert(AVLNODE<T>*& root, const T& elem, bool& insert_side, int (*Compare)(const T& x, const T& y), bool& is_exit);
	static int IsBalanced(AVLNODE<T>* x);
	static void AdjustHeight(AVLNODE<T>*& x);
	static int Height(const AVLNODE<T>* root);
	static void Left_rotating(AVLNODE<T>*& root);
	static void Right_rotating(AVLNODE<T>*& root);
	static void Lr_double_rotating(AVLNODE<T>*& root);
	static void Rl_double_rotating(AVLNODE<T>*& root);
	static void GetData(AVLNODE<T>* root, T** elems, int& pos);
	static void Find(const AVLNODE<T>* root, T& target, int (*Compare)(const T& x, const T& y));
	int data_number;
	AVLNODE<T>* root;
};

template <typename T>
AVLTREE<T>::AVLTREE()
{
	root = NULL;
	data_number = 0;
}

template <typename T>
AVLTREE<T>::~AVLTREE()
{
	if(root != NULL)
	{
		Destroy(root);
	}
}

template <typename T>
AVLTREE<T>::AVLTREE(const AVLTREE<T>& x)
{
	Copy(root, x.root);
	data_number = x.data_number;
}

template <typename T>
const AVLTREE<T>& AVLTREE<T>::operator =(const AVLTREE<T>& x)
{
	Destroy(root);
	data_number = x.data_number;
	Copy(root, x.root);
	return *this;
}

template <typename T>
void AVLTREE<T>::Insert(const T& x, int (*Compare)(const T& x, const T& y))
{
	bool insert_side; 
	Insert(root, x, insert_side, Compare);
	data_number ++;
}

template <typename T>
AVLNODE<T>* AVLTREE<T>::SetInsert(const T& x, int (*Compare)(const T& x, const T& y))
{
	bool insert_side, is_exist = false;
	AVLNODE<T>* result;
	result = Insert(root, x, insert_side, Compare, is_exist);
	if(!is_exist)
	{
		data_number ++;
	}
	return result;
}

template <typename T>
int AVLTREE<T>::DataNumber()const
{
    return data_number;
}



template <typename T>
void AVLTREE<T>::Find(T& target, int (*Compare)(const T& x, const T& y))const
{
     Find(root, target, Compare);     
}

template <typename T>
void AVLTREE<T>::Display()const
{
	Display(root);
}

template <typename T>
void AVLTREE<T>::Display(const AVLNODE<T>* root)
{
	if(root != NULL)
	{
		Display(root->lchild);
		root->data.Output();
		cout << endl;
		Display(root->rchild);
	}
}
template <typename T>
void AVLTREE<T>::Destroy(AVLNODE<T>*& root)
{
	/*
	AVLNODE<T> *lchild = NULL, *rchild = NULL;
	lchild = root->lchild;
	if(lchild != NULL)
	{
		Destroy(lchild);
	}
	rchild = root->rchild;
	if(rchild != NULL)
	{
		Destroy(lchild);
	}
	*/
	if(root != NULL)
	{
		if(root->lchild != NULL)
		{
			Destroy(root->lchild);
		}
		if(root->rchild != NULL)
		{
			Destroy(root->rchild);
		}
		delete [] root;
		root = NULL;
	}
}


template <typename T>
void AVLTREE<T>::Copy(AVLNODE<T>*& root_recieve, const AVLNODE<T>* root_give)
{
	if(root_give != NULL)
	{
		root_recieve = new AVLNODE<T>(root_give->data, root_give->height);
		Copy(root_recieve->lchild, root_give->lchild);
		Copy(root_recieve->rchild, root_give->rchild);
	}
}

template <typename T>
int AVLTREE<T>::Height(const AVLNODE<T>* x)
{
	int result;
	if(x == NULL) result = -1;
	else result = x->height;
	return result;
}

template <typename T>
void AVLTREE<T>::Insert(AVLNODE<T>*& root, const T& elem, bool& insert_side, int (*Compare)(const T& x, const T& y))
{
	int balance_degree;
	if(root != NULL)
	{
		if(Compare(elem, root->data) <= 0)
		{
			insert_side = left_insert;
			Insert(root->lchild, elem, insert_side, Compare);
		}
		else
		{
			insert_side = right_insert;
			Insert(root->rchild, elem, insert_side, Compare);
		}

	}
	else
	{
		root = new AVLNODE<T>(elem);
	}
	AdjustHeight(root);
	balance_degree = IsBalanced(root);
	if(balance_degree == 2)
	{
		if(insert_side == left_insert)
		{
			Right_rotating(root);
		}
		else
		{
			Lr_double_rotating(root);
		}
	}
	else if(balance_degree == -2)
	{
		if(insert_side == left_insert)
		{
			Rl_double_rotating(root);
		}
		else
		{
			Left_rotating(root);
		}
	}
}

template <typename T>
AVLNODE<T>* AVLTREE<T>::Insert(AVLNODE<T>*& root, const T& elem, bool& insert_side, int (*Compare)(const T& x, const T& y), bool& is_exist)
{
	AVLNODE<T>* result = NULL;
	int compare_result;
	int balance_degree;
	if(root != NULL)
	{
		compare_result = Compare(elem, root->data);
		if(compare_result < 0)
		{
			insert_side = left_insert;
			result = Insert(root->lchild, elem, insert_side, Compare, is_exist);
		}
		else if(compare_result > 0)
		{
			insert_side = right_insert;
			result = Insert(root->rchild, elem, insert_side, Compare, is_exist);
		}
		else
		{
			is_exist = true;
			return root;
		}
	}
	else
	{
		return root = new AVLNODE<T>(elem);
	}
	AdjustHeight(root);
	balance_degree = IsBalanced(root);
	if(balance_degree == 2)
	{
		if(insert_side == left_insert)
		{
			Right_rotating(root);
		}
		else
		{
			Lr_double_rotating(root);
		}
	}
	else if(balance_degree == -2)
	{
		if(insert_side == left_insert)
		{
			Rl_double_rotating(root);
		}
		else
		{
			Left_rotating(root);
		}
	}
	return result;
}

template <typename T>
int AVLTREE<T>::IsBalanced(AVLNODE<T>* x)
{
	int delt;
	AVLNODE<T> *p, *q;
	p = x->lchild;
	q = x->rchild;
	delt = Height(p) - Height(q);
	return delt;
}

template <typename T>
void AVLTREE<T>::Left_rotating(AVLNODE<T>*& root)
{
	AVLNODE<T> *p;
	p = root->rchild;
	root->rchild = p->lchild;
	p->lchild = root;
	AdjustHeight(root);
	AdjustHeight(p);
	root = p;
}

template <typename T>
void AVLTREE<T>::Right_rotating(AVLNODE<T>*& root)
{
	AVLNODE<T> *p;
	p = root->lchild;
	root->lchild = p->rchild;
	p->rchild = root;
	AdjustHeight(root);
	AdjustHeight(p);
	root = p;
}

template <typename T>
void AVLTREE<T>::Lr_double_rotating(AVLNODE<T>*& root)
{
	Left_rotating(root->lchild);
	Right_rotating(root);
}

template <typename T>
void AVLTREE<T>::Rl_double_rotating(AVLNODE<T>*& root)
{
	Right_rotating(root->rchild);
	Left_rotating(root);
}

template <typename T>
void AVLTREE<T>::AdjustHeight(AVLNODE<T>*& root)
{
	int left_height, right_height;
	left_height = Height(root->lchild);
	right_height = Height(root->rchild);
	root->height = (left_height > right_height ? left_height : right_height) + 1;
}

template <typename T>
void AVLTREE<T>::GetData(T**& elems)
{
	int pos = 0;
	elems = new T*[data_number];
	GetData(root, elems, pos);
}

template <typename T>
void AVLTREE<T>::GetData(AVLNODE<T>* root, T** elems, int& pos)
{
	if(root != NULL)
	{
		elems[pos] = &root->data;
		pos ++;
		GetData(root->lchild, elems, pos);
		GetData(root->rchild, elems, pos);
	}
}

template <typename T>
void AVLTREE<T>::Find(const AVLNODE<T>* root, T& target, int (*Compare)(const T& x, const T& y))
{
     int k;
     if(root != NULL)
     {
         k = Compare(root->data, target);
         if(k < 0)
         {
             Find(root->rchild, target, Compare);
         }
         else if(k > 0)
         {
              Find(root->lchild, target, Compare);
         }
         else
         {
             target = root->data;
         }
     }
}
#endif

