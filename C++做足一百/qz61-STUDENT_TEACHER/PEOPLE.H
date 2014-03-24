#ifndef _PEOPLE_H_

#define _PEOPLE_H_

#include "MYDATE.H"

class PEOPLE
{
public:
	void SetId();
	void SetName();
	void SetGender();
	void SetBirth();
	char* GetId();
	char* GetName();
	bool GetGender();
	MYDATE GetBirth();
	void Birth();
protected:
	char id[17], name[10];
	bool gender;
	MYDATE	birth;
};

#endif