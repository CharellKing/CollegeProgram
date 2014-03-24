#ifndef _NODE_H_

#define _NODE_H_

class NODE
{
public:
	NODE(double components = 0, NODE *next = NULL);
	double& Components();
	NODE*& Next();
private:
	double components;
	NODE *next;
};

#endif