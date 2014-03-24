#ifndef _STUDENT_H_

#define _STUDENT_H_

#include "PEOPLE.H"

class STUDENT: virtual public PEOPLE
{
public:
	void SetSlid();
	char* GetSlid();
protected:
	char slid[11];
};

#endif