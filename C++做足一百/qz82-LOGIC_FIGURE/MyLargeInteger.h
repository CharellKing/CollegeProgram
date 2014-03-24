#ifndef _MyLargeInteger_h_

#define _MyLargeInteger_h_

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

#endif
