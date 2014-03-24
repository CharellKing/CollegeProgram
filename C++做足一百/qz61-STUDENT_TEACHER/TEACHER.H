#ifndef _TEACHER_H_

#define _TEACHER_H_

#include "PEOPLE.H"

enum TITLE {ASSISTANT, LECTURE, ASSOCIATE_PROFESSOR, PROFESSOR};

class TEACHER: virtual public PEOPLE
{
public:
	void SetPosition();
	TITLE GetPosition();
	void Position();
protected:
	TITLE position;
};

#endif