#ifndef _MyLargeInteger_h_

#define _MyLargeInteger_h_

#include <stdio.h>

#include <ctype.h>

#define M 500

void ClearZero (char *p, int n);//清零

void InputLargeInteger(char *p, int n); // 输入大整数

void OutputLargeInteger(const char *q, int n); // 输出大整数

void AddLargeInteger(char *r, const char *p, const char *q, int n); // 大整数p和q相加, 结果保存到r

void MulLargeInteger(char *r, const char *p, const char *q, int n); // 大整数p和q相乘, 结果保存到r

enum Isvalid Judgevalid (const char *r, int n);

enum Isvalid {NO, YES};

#endif
