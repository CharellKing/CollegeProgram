#include <iostream>

#include <cstring>

#include "Family.H"

using namespace std;

FAMILY::FAMILY()
{
	member_num = 0;
}

void FAMILY::Insert(int num, const char *name)
{
	if(num < MAXSIZE && num > 0)
	{
		member_num ++;
		strcpy(members[num].name, name);
		if(num != 1)
		{
			members[num].parent = num / 2;
			if(num % 2 == 0)
			{
				members[members[num].parent].lchild = num;
			}
			else
			{
				members[members[num].parent].rchild = num;
			}
		}
	}
	else
	{
		cout << "序列号只能从1到" << MAXSIZE - 1 <<
			", 对不起， 超界了!" << endl;
		cout << "添加失败!" << endl;
	}
}

void FAMILY::Traversal()
{
	int start = 1, end = 1, k = 0, generation = 1, i;
	do
	{
		for(i = start; i <= end && k < member_num; i ++)
		{
			if(i == start)
			{
				cout << "第" << generation << "代: ";
			}
			if(members[i].name[0] != '\0')
			{
				cout << members[i].name << ' ';
				k ++;
			}
		}
		cout << endl;
		generation ++;
		start = end + 1;
		end = end * 2 + 1;
	}
	while(k < member_num);
}

int FAMILY::FindPerson(const char* name)
{
	int i;
	for(i = 1; i < MAXSIZE && strcmp(members[i].name, name) != 0; i ++);
	if(i == MAXSIZE) i = 0;
	return i;
}

void FAMILY::PrintAncestors(const char* name)
{
	int i;
	i = FindPerson(name);
	if(i == 0)
	{
		cout << "家族中无此人!" << endl;
	}
	else
	{
		if(i == 1)
		{
			cout << "不知其祖先!" << endl;
		}
		else
		{
			i = members[i].parent;
			while(i != 0)
			{
				cout << members[i].name << ' ';
				i = members[i].parent;
			}
			cout << endl;
		}
	}
}



