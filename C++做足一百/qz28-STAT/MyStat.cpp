#include <iostream>

using namespace std;

#include "MyStat.h"

void Init(NODE* &head)
{
	head = new NODE;
	head->next = NULL;
	head->num = 0;
}

void Append(NODE* &head) //输出: 输出数组中的全部正实数
{
	NODE* p = head, *s;
	double x;
	while(p->next != NULL) p = p->next;
	while(cin >> x, x)
	{
		s = new NODE;
		s->next = p->next;
		p->next = s;
		s->num = x;
		p = s;
	}
	p->next = NULL;
}

void List(NODE* head) //统计: 求数组中正实数的总和、最大值、最小值和平均值
{
	NODE *p = head->next;
	while(p)
	{
		cout << "  " << p->num;
		p = p->next;
	}
	cout << endl;
}

void Stat(NODE* head, double &sum, double &max, double &min, double &avg)
//查找: 查找数组中第一个值为x的实数, 若查找成功, 则返回其位置(1~n), 否则返回0
{
	NODE *p = head;
	int n = 0;
	max = 1e-7;
	min = 1e7;
	sum = 0;
	while(p = p->next)
	{
		sum += p->num;
		if(p->num > max) max = p->num;
		if(p->num < min) min = p->num;
		n ++;
	}
	avg = sum / n;
}

int Find(NODE* head, double x) //排序: 用冒泡法对数组按升序排序
{
	NODE *p = head;
	int n = 1;
	while((p = p->next) && p->num != x) n ++;
	if(!p) n = 0;
	return n;
}


void Sort(NODE* &head)//交换: 交换正实数x和y的值
{
	NODE *p = head, *q, *s;
	while((p = p->next))
	{
		s = q = p;
		while((q = q->next))
		{
			if(q->num < s->num) s = q;
		}
		Swap(p->num, s->num);
	}
}

static void Swap(double &x, double &y)
{
	double z;
	z = x;
	x = y;
	y = z;
}