#ifndef _MYSTAT_H_

#define  _MYSTAT_H_

struct NODE
{
	double num;
	NODE *next;
};

void Init(NODE* &x);
//��ʼ��

void Append(NODE* &x);
//���: ��������е�ȫ����ʵ��

void List(NODE* head);
//ͳ��: ����������ʵ�����ܺ͡����ֵ����Сֵ��ƽ��ֵ

void Stat(NODE* head, double &sum, double &max, double &min, double &avg);
//����: ���������е�һ��ֵΪx��ʵ��, �����ҳɹ�, �򷵻���λ��(1~n), ���򷵻�0

int Find(NODE* head, double x);
//����: ��ð�ݷ������鰴��������

void Sort(NODE* &head);
//����: ������ʵ��x��y��ֵ

void Swap(double &x, double &y);


#endif