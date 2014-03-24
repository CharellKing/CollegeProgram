#ifndef _AVLNODE_H_

#define _AVLNODE_H_

template <typename T>
class AVLNODE
{
public:
	AVLNODE(T data = T(), int height = 0, AVLNODE* lchild = NULL, AVLNODE* rchild = NULL);
	T data;
	int height;
	AVLNODE *lchild, *rchild;
};

template <typename T>
AVLNODE<T>::AVLNODE(T data, int height, AVLNODE* lchild, AVLNODE* rchild)
{
	this->data = data;
	this->height = height;
	this->lchild = lchild;
	this->rchild = rchild;
}

#endif