//3.	������������
//������������ʾ�޷��Ŵ�����, ��ɴ����������롢������ӷ��ͳ˷����㡣
//void InputLargeInteger(char *p, int n); // ���������
//void OutputLargeInteger(const char *q, int n); // ���������
//void AddLargeInteger(char *r, const char *p, const char *q, int n); // ������p��q���, ������浽r
//void MulLargeInteger(char *r, const char *p, const char *q, int n); // ������p��q���, ������浽r




#include <stdio.h>

#include <ctype.h>

#define M 500

void ClearZero (char *p, int n);//����

void InputLargeInteger(char *p, int n); // ���������

void OutputLargeInteger(const char *q, int n); // ���������

void AddLargeInteger(char *r, const char *p, const char *q, int n); // ������p��q���, ������浽r

void MulLargeInteger(char *r, const char *p, const char *q, int n); // ������p��q���, ������浽r

enum Isvalid Judgevalid (const char *r, int n);

enum Isvalid {NO, YES};

int main()
{
	char LargeInteger1[M], LargeInteger2[M], LargeInteger3[M], LargeInteger4[M];
	
	ClearZero (LargeInteger1, M);
	ClearZero (LargeInteger2, M);
	ClearZero (LargeInteger3, M);
	ClearZero (LargeInteger4, M);
	
	printf("Input the largeIntegers from the highest digit to lowest digit:\n");

	printf("Please input the 'LargeInteger1:\n");
	InputLargeInteger(LargeInteger1, M);

	printf("Please input the 'LargeInteger2:\n");
	InputLargeInteger(LargeInteger2, M);

	printf("Two large integer add :\n");
	AddLargeInteger(LargeInteger3, LargeInteger2,LargeInteger1, M); // ������p��q���, ������浽r
	OutputLargeInteger(LargeInteger3, M); // ���������

	printf("Two large integer multiply: :\n");
	MulLargeInteger(LargeInteger4, LargeInteger2,LargeInteger1, M); // ������p��q���, ������浽r
	OutputLargeInteger(LargeInteger4,  M); // ���������

	return 0;
}

void ClearZero (char *p, int n)//����
{
	int i;
	for(i = 1; i < n; i ++)
	{
		p[i] = '0';
	}
}

Isvalid Judgevalid (const char *r, int n)
{
	enum Isvalid k = YES;
	if((!isdigit(r[1])) || (r[1] == '0' && isdigit(r[2]))) k = NO;
	return k;
}
	

void InputLargeInteger(char *p, int n)// ���������
{
	int i = 1, k, m;
	char q[M];
	do
	{
		do
		{
			scanf("%c", &q[i]);
			m = isdigit(q[i]);
			i ++;
		}
		while(m);
		k = i - 2;
		m = (!Judgevalid (q, k));
		if(m) printf("This large integer is not valid, please input it again!\n");
	}
	while(m);
	for(i = 1; k >= 1; k --, i ++)
	{
		p[i] = q[k];
	}
}

void OutputLargeInteger(const char *q, int n) // ���������
{
	int i = n - 1;
	for(; q[i] == '0'; i--);
	//putchar(q[i+1]);
	for(; i >= 1; i --)
	{
		putchar(q[i]);
	}
	printf("\n");
}

void AddLargeInteger(char *r, const char *p, const char *q, int n) // ������p��q���, ������浽r
{
	int i, c;
	for(i = 1; i < n; i ++)
	{
		c = (p[i] - '0') + (q[i] - '0');
		r[i] += c % 10;
		r[i + 1] += c / 10;
	}
}

void MulLargeInteger(char *r, const char *p, const char *q, int n) // ������p��q���, ������浽r
{
	int i, j, a, b, d;
	for(i = 1; i < n; i ++)
	{
		for(j = 1; j < n; j ++)
		{
			d = i + j - 1;
			a = (p[i] - '0') * (q[j] - '0');
			r[d] += (a % 10);
			r[d + 1] += (a / 10);
			do
			{
				b = r[d] - '0';
				r[d] = '0' + b % 10;
				r[d + 1] += (b / 10);
				d ++;
			}
			while(!isdigit(r[d + 1]));
		}
	}
}

