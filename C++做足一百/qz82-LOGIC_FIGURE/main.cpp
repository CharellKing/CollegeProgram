//3.	������������
//������������ʾ�޷��Ŵ�����, ��ɴ����������롢������ӷ��ͳ˷����㡣
//void InputLargeInteger(char *p, int n); // ���������
//void OutputLargeInteger(const char *q, int n); // ���������
//void AddLargeInteger(char *r, const char *p, const char *q, int n); // ������p��q���, ������浽r
//void MulLargeInteger(char *r, const char *p, const char *q, int n); // ������p��q���, ������浽r




#include <stdio.h>

#include <ctype.h>

#include "MyLargeInteger.h"

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

