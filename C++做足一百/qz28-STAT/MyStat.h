#ifndef _MYSTAT_H_

#define  _MYSTAT_H_

struct NODE
{
	double num;
	NODE *next;
};

void Init(NODE* &x);
//初始化

void Append(NODE* &x);
//输出: 输出数组中的全部正实数

void List(NODE* head);
//统计: 求数组中正实数的总和、最大值、最小值和平均值

void Stat(NODE* head, double &sum, double &max, double &min, double &avg);
//查找: 查找数组中第一个值为x的实数, 若查找成功, 则返回其位置(1~n), 否则返回0

int Find(NODE* head, double x);
//排序: 用冒泡法对数组按升序排序

void Sort(NODE* &head);
//交换: 交换正实数x和y的值

void Swap(double &x, double &y);


#endif