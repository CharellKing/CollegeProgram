#include <iostream>

using namespace std;

#include "MyStat.h"

void Init(NODE* &head)
{
	head = new NODE;
	head->next = NULL;
	head->num = 0;
}

void Append(NODE* &head) //���: ��������е�ȫ����ʵ��
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

void List(NODE* head) //ͳ��: ����������ʵ�����ܺ͡����ֵ����Сֵ��ƽ��ֵ
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
//����: ���������е�һ��ֵΪx��ʵ��, �����ҳɹ�, �򷵻���λ��(1~n), ���򷵻�0
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

int Find(NODE* head, double x) //����: ��ð�ݷ������鰴��������
{
	NODE *p = head;
	int n = 1;
	while((p = p->next) && p->num != x) n ++;
	if(!p) n = 0;
	return n;
}


void Sort(NODE* &head)//����: ������ʵ��x��y��ֵ
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