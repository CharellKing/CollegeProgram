#include <iostream>

using namespace std;

#include <conio.h>

#include <cctype>

#include "Family.h"

#include "MEMBER.H"

const char Menu(const char* items, const char* choice)
{
	char c;
	cout << items;
	while(strchr(choice, c = toupper(getch())) == NULL);
	cout << c << endl;
	return c;
}

const MEMBER members[12] = {"����", 1, "��ϲ", 2, "����", 3, "��˶", 4, "��ʯ", 5, 
"����", 6, "����", 7, "����", 8, "��ӿ", 9, "����", 11, "����", 13, "����", 27};

int main()
{
	FAMILY a;
	int i;
	char c;
	char name[10];
	for(i = 0; i < 12; i ++)
	{
		a.Insert(members[i].num, members[i].name);
	}
	do
	{
		switch(c = Menu("***************\n"
						"T---�������--*\n"
						"S---��ȡ����--*\n"
						"Q---��    ��--*\n"
						"***************\n", "TSQ"))
		{
		case 'T':
			cout << "��ӡ������Ա:" << endl;
			a.Traversal();
			break;
		case 'S':
			cout << "������ĳ���Ӵ�������:";
			cin >> name;
			cout << "��ӡ������:" << endl;
			a.PrintAncestors(name);
			break;
		}
	}
	while(c != 'Q');
	return 0;
}