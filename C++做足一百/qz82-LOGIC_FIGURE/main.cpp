//3.	大整数的运算
//利用数组来表示无符号大整数, 完成大整数的输入、输出、加法和乘法运算。
//void InputLargeInteger(char *p, int n); // 输入大整数
//void OutputLargeInteger(const char *q, int n); // 输出大整数
//void AddLargeInteger(char *r, const char *p, const char *q, int n); // 大整数p和q相加, 结果保存到r
//void MulLargeInteger(char *r, const char *p, const char *q, int n); // 大整数p和q相乘, 结果保存到r




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
	AddLargeInteger(LargeInteger3, LargeInteger2,LargeInteger1, M); // 大整数p和q相加, 结果保存到r
	OutputLargeInteger(LargeInteger3, M); // 输出大整数

	printf("Two large integer multiply: :\n");
	MulLargeInteger(LargeInteger4, LargeInteger2,LargeInteger1, M); // 大整数p和q相乘, 结果保存到r
	OutputLargeInteger(LargeInteger4,  M); // 输出大整数

	return 0;
}

