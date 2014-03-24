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

void List(LIST head); //ͳ��: ����������ʵ�����ܺ͡����ֵ����Сֵ��ƽ��ֵ

void Sort(LIST &head);//����: ������ʵ��x��y��ֵ

void Remove(LIST &head, string s);

void Swap(string &x, string &y);

void Modify(LIST &head, string s1, string s2);

int Find(LIST head, string s);

#endif
