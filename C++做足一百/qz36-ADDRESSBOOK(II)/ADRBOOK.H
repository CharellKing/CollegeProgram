#ifndef _ADRBOOK_H_

#define _ADRBOOK_H_

#include "Person.h"

struct NODE
{
	PERSON aPerson;
	NODE *next;
};

struct ADDRESSBOOK
{
	char filename[15];
	NODE *head;
};

typedef NODE* LNODE;

void Init(LNODE &head);

void Append(LNODE &head, const PERSON &x);

void List(LNODE &head);

void Remove(LNODE &head, const char *s);

void Search(LNODE &head);

void ShowIndexConditions();

void ShowChoosedColumn(char *c, const char *column[]);

bool NoFind(const char *c, const char x);

void Swap(char &x, char &y);

void SortNum(char *c);

void SetPersonInformation(int k , PERSON &x);

void Evaluate(LNODE &p, const PERSON &x, const char c);

void ShowChoosedColumn(const bool *b, const char *column[]);

void Reference(LNODE &head, const PERSON &x, const bool *b);

void Modify(LNODE &head, const char *s);

void OutPersonInformation(int k , PERSON &x);

void Sort(LNODE &head);

char IsMax(const PERSON &x , const PERSON &y, const char c);

int IsDateMax(const DATE &x, const DATE &y);

void SwapPerson(PERSON &x, PERSON &y);

void Show(LNODE &head);

void Clear(LNODE &head);


#endif
