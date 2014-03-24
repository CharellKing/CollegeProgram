#ifndef _MYPRODUCTLIST_H

#define _MYPRODUCTLIST_H

struct NODE
{
	string productname;
	NODE *next;
};

typedef NODE* LIST;

void Init(LIST &x);

void Append(LIST &x, string s);

void List(LIST head); //统计: 求数组中正实数的总和、最大值、最小值和平均值

void Sort(LIST &head);//交换: 交换正实数x和y的值

void Remove(LIST &head, string s);

void Swap(string &x, string &y);

void Modify(LIST &head, string s1, string s2);

int Find(LIST head, string s);

#endif
