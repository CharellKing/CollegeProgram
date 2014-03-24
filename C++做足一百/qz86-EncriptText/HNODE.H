#ifndef _HNODE_H_

#define _HNODE_H_

template <typename T>
class HNODE
{
public:
	HNODE(T data = T(), int parent = -1, int lchild = -1, int rchild = -1);
	void Output()const;
	T data;
	int parent, lchild, rchild;
};

template <typename T>
HNODE<T>::HNODE(T data, int parent, int lchild, int rchild)
{
	this->data = data;
	this->parent = parent;
	this->lchild = lchild;
	this->rchild = rchild;
}

template <typename T>
void HNODE<T>::Output()const
{
	cout << "( ";
	data.Output();
	cout << ", " << parent << ", " << lchild  << ", " << rchild << endl;
}

#endif