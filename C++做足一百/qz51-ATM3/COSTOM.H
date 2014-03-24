#ifndef _COSTOM_H_

#define _COSTOM_H_

#include "MYDATE.H"

struct ID
{
	char name[15], homeAdr[50], nation[20], id_NO[17];
	MYDATE birthday;
	bool gender;
};

struct PERSON
{
	char account[16], code[7];
	double fund;
	ID id;
};

class COSTOM
{
public:
	COSTOM();
	void Account();
	void Code();
	void PersonInfo();
	void Save(double fund);
	void Withdrawl(double fund);
	const char* GetAccount()const;
	const char* GetCode()const;
	const char* GetName()const;
	const char* GetHomeAdr()const;
	const char* GetNation()const;
	const char* GetId_NO()const;
	MYDATE GetBirthday()const;
	bool GetGender()const;
	void OutputBirthday()const;
	double Fund()const;
private:
	PERSON aCostom;
};

#endif