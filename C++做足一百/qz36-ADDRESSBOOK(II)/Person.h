#ifndef _PERSON_H_

#define _PERSON_H_

#include "MyDate.h"

struct PERSON
{
	DATE birthday, entrance;
	char studentnum[15], group[20], name[20], mobileTel[20], room[15], roomTel[20], homeAdr[50], postcode[7], homeTel[20],
		email[30], qq[15]; 
	bool gender;
};

void Input(PERSON &x);

void Output(const PERSON &x);

#endif