#ifndef _GRADUATE_H_

#define _GRADUATE_H_

#include <string>

#include "TEACHER.H"

#include "STUDENT.H"

class GRADUATE : public TEACHER, public STUDENT
{
public:
	void SetField();
	string GetField() const;
protected:
	string field;
};

#endif