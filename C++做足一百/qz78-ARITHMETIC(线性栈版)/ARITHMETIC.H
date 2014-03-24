#ifndef _ARITHMETIC_H_

#define _ARITHMETIC_H_

#include "STACK.H"

class ARITHMETIC
{
public:
	ARITHMETIC();
	void Begin();
	void Express();
	void Space();
	void Real();
	static bool IsOperator(char c);
	static char Precede(char c1, char c2);
	static char Char_value(char c);
	void Operator(double x, char c, double y);
	double Result();
	void ShowErr();
protected:
	char current;
	int pos;
	int match;
	STACK<double> opnd;
	STACK<char> oprt;
};



#endif