#include <iostream>

using namespace std;

#include "MyFile.h"

#include "ADRBOOK.H"

#include "MyMenu.h"

FILE* WriteIn(ADDRESSBOOK &x)
{
	LNODE p = x.head;
	FILE *fp; 
	fp = fopen(x.filename, "wb");
	if(fp)
	{
		while(p = p->next)
		{
			fwrite(&p->aPerson, sizeof(PERSON), 1, fp);
		}
		fclose(fp);
	}
	else
	{
		cout << "文件无法打开!\n";
	}
	return fp;
}

FILE* ReadOut(ADDRESSBOOK &x)
{
	LNODE p = x.head, s;
	FILE *fp;
	PERSON a;
	fp = fopen(x.filename, "rb");
	if(fp)
	{
		Clear(x.head);
		while(fread(&a, sizeof(PERSON), 1, fp) == 1)
		{
			s = new NODE;
			s->aPerson = a;
			p->next = s;
			p = s;
		}
		p->next = NULL;
		fclose(fp);
	}
	return fp;
}

bool IsExistent(ADDRESSBOOK &x)
{ 
	char c;
	bool b = true;
	if(ReadOut(x) == NULL)
	{
		b = false;
		c = Menu("是否新建该文件:(Y - yes, N - no)", "YN");
		if(c == 'N')
		{
			cout << "重新输入文件名:";
			cin >> x.filename;
		}
		if(c == 'Y')
		{
			Clear(x.head);
		}
	}
	return b;
}


