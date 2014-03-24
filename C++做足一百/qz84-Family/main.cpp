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

const MEMBER members[12] = {"王威", 1, "王喜", 2, "王嘉", 3, "王硕", 4, "王石", 5, 
"王磊", 6, "王燕", 7, "王波", 8, "王涌", 9, "王海", 11, "王涛", 13, "王帆", 27};

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
						"T---按层遍历--*\n"
						"S---获取祖先--*\n"
						"Q---结    束--*\n"
						"***************\n", "TSQ"))
		{
		case 'T':
			cout << "打印各代成员:" << endl;
			a.Traversal();
			break;
		case 'S':
			cout << "请输入某个子代的名字:";
			cin >> name;
			cout << "打印其祖先:" << endl;
			a.PrintAncestors(name);
			break;
		}
	}
	while(c != 'Q');
	return 0;
}