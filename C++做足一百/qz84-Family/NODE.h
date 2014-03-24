#ifndef _NODE_H_

#define _NODE_H_

class NODE
{
public:
	NODE(char *name = "", int parent = 0, int lchild = 0, int rchild = 0);
	int parent;
	int rchild;
	int lchild;
	char name[10];
};

#endif