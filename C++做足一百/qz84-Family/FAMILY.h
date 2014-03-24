#ifndef _FAMILY_H_

#define _FAMILY_H_

#include "NODE.H"

const unsigned MAXSIZE = 500;

class FAMILY
{
public:
	FAMILY();
	void Insert(int num, const char *name);
	void Traversal();
	int FindPerson(const char* name);
	void PrintAncestors(const char* name);
protected:
	NODE members[MAXSIZE];
	int member_num;
};


#endif