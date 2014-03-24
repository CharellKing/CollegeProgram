#ifndef _MYFILE_H_

#define _MYFILE_H_

#include "ADRBOOK.H"

FILE* WriteIn(ADDRESSBOOK &x);

FILE* ReadOut(ADDRESSBOOK &x);

bool IsExistent(ADDRESSBOOK &x);

#endif