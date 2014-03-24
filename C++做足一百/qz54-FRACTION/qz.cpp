//��Coord.h����������ĺ�������, ����Coord.cpp�ж���ú���, �������������ε������
//REAL TriangleArea(const struct COORD *p, const struct COORD *q, const struct COORD *r);
//�޸�������, �������������, �������������㹹�ɵ������ε������


#include <stdio.h>

#include <math.h>

typedef double REAL;

void InputCoord(struct COORD *p); // ��������

void OutputCoord(const struct COORD *p); // �������, ��: (3, 4)

REAL TriangleArea(const struct COORD *p, const struct COORD *q, const struct COORD *r);

REAL Distance(const struct COORD *p, const struct COORD *q); // �������������*p��*q֮��ľ���


struct COORD{double x, y;};

int main()
{
	struct COORD a, b, c;
	printf("a = ? ");
	InputCoord(&a); // ����a������
	printf("b = ? ");
	InputCoord(&b); // ����b������
	printf("c = ?");
	InputCoord(&c); // ����c������
	printf("a = ");
	OutputCoord(&a); // ���a������
	printf("\n");
	printf("b = ");
	OutputCoord(&b); // ���b������
	printf("\n");
	printf("c = ");
	OutputCoord(&c); // ���b������
	printf("\n");
	printf("�������ε����Ϊ:%lg\n", TriangleArea(&a, &b, &c));
	return 0;
}

void InputCoord(struct COORD *p) // ��������
{
	scanf("%lg %lg", &p->x, &p->y);
}

void OutputCoord(const struct COORD *p) // �������, ��: (3, 4)
{
	printf("����Ϊ(%lg, %lg)\n", p->x, p->y);
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


REAL Distance(const struct COORD *p, const struct COORD *q) // �������������*p��*q֮��ľ���
{
	double s, m, n;
	m = p->x - q->x;
	n = p->y - q->y;
	s = sqrt(m * m + n * n);
	return s;
}