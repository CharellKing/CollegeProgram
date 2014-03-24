#ifndef _ATM_H_

#define _ATM_H_

#include "COSTOM.H"

#include <string>

struct NODE
{
	COSTOM aCostom;
	NODE *next;
};

typedef NODE* LNODE;

class ATM
{
public:
	ATM();
	~ATM();
	//void List();
	void Account();
	void Save();
	void Modify_Code();
	void Show_Fund();
	void Withdrawl();
	char InSystem();
	//string Lock();
private:
	void Append(const COSTOM &x);
	LNODE Exist(const char *s);
	void Output(const COSTOM &x);
	void ReadOut();
	void WriteIn();
	void Cover(const COSTOM &x);
	LNODE head;
	COSTOM aCostom;
};

#endif