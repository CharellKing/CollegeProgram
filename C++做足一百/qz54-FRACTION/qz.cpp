//在Coord.h中增加下面的函数声明, 并在Coord.cpp中定义该函数, 用来计算三角形的面积。
//REAL TriangleArea(const struct COORD *p, const struct COORD *q, const struct COORD *r);
//修改主函数, 输入三个坐标点, 计算由这三个点构成的三角形的面积。


#include <stdio.h>

#include <math.h>

typedef double REAL;

void InputCoord(struct COORD *p); // 输入坐标

void OutputCoord(const struct COORD *p); // 输出坐标, 例: (3, 4)

REAL TriangleArea(const struct COORD *p, const struct COORD *q, const struct COORD *r);

REAL Distance(const struct COORD *p, const struct COORD *q); // 计算两个坐标点*p和*q之间的距离


struct COORD{double x, y;};

int main()
{
	struct COORD a, b, c;
	printf("a = ? ");
	InputCoord(&a); // 输入a点坐标
	printf("b = ? ");
	InputCoord(&b); // 输入b点坐标
	printf("c = ?");
	InputCoord(&c); // 输入c点坐标
	printf("a = ");
	OutputCoord(&a); // 输出a点坐标
	printf("\n");
	printf("b = ");
	OutputCoord(&b); // 输出b点坐标
	printf("\n");
	printf("c = ");
	OutputCoord(&c); // 输出b点坐标
	printf("\n");
	printf("此三角形的面积为:%lg\n", TriangleArea(&a, &b, &c));
	return 0;
}

void InputCoord(struct COORD *p) // 输入坐标
{
	scanf("%lg %lg", &p->x, &p->y);
}

void OutputCoord(const struct COORD *p) // 输出坐标, 例: (3, 4)
{
	printf("坐标为(%lg, %lg)\n", p->x, p->y);
}

REAL TriangleArea(const struct COORD *p, const struct COORD *q, const struct COORD *r)
{
	double a, b, c, s, area;
	a = Distance(p, q);
	b = Distance(p, r);
	c = Distance(q, r);
	s = (a + b + c) / 2;
	area = sqrt(s * (s - a) * (s - b) * (s - c));
	return area;
}


REAL Distance(const struct COORD *p, const struct COORD *q) // 计算两个坐标点*p和*q之间的距离
{
	double s, m, n;
	m = p->x - q->x;
	n = p->y - q->y;
	s = sqrt(m * m + n * n);
	return s;
}