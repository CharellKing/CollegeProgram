#include "NODE.H"

#include <cstring>

NODE::NODE(char *name, int parent, int lchild, int rchild)
{
	strcpy(this->name, name);
	this->parent = parent;
	this->lchild = lchild;
	this->rchild = rchild;
}
