#include <iostream>

using namespace std;

#include <conio.h>

#include <string>

#include "ARITHMETIC.H"

ARITHMETIC::ARITHMETIC()
{
	pos = 0;
	match = 0;
}

void ARITHMETIC::Begin()
{
	try
	{
		Express();
		cout << Result() << endl;
	}
	catch(int)
	{
		ShowErr();
	}
	catch(string x)
	{
		cout << endl;
		cout << x << endl;
	}
}

void ARITHMETIC::Express()
{
	int k;
	char prior;
	Space();
	k = 1;
	while(current != 13)
	{
		if(k % 2)
		{
			if(current == '(')
			{
				oprt.Push(current);
				match ++;
				Space();
			}
			else if(!isdigit(current) && current != '+' && current != '-')
			{
				throw 1;
			}
			else
			{
				Real();
				k ++;
			}
		}
		else
		{
			if(IsOperator(current))
			{
				if(current == ')')
				{
					if(oprt.Top() == '(')
					{
						oprt.Pop();
						Space();
					}
					else
					{
						Operator(opnd.Pop(), oprt.Pop(), opnd.Pop());
					}
				}
				else
				{
					if(oprt.Length() >= 1)
					{
						prior = Precede(oprt.Top(), current);
						if(prior == '>')
						{
							if(oprt.Top() != '(')
							{
								Operator(opnd.Pop(), oprt.Pop(), opnd.Pop());
							}
						}
					}
					k ++;
					oprt.Push(current);
					Space();
				}
			}
			else
			{
				throw 1;
			}
		}
		if(match < 0)
		{
			throw 1;
		}
	}
	if(match != 0)
	{
		throw 1;
	}
	while(opnd.Length() != 1)
	{
		Operator(opnd.Pop(), oprt.Pop(), opnd.Pop());
	}
	cout << endl;
}

void ARITHMETIC::Space()
{
	while(current = getch(), current == ' ' || current == '\b')
	{
		if(current == ' ')
		{
			cout << current;
		}
		pos ++;
	}
	cout << current;
	if(current == ')') match --;
	pos ++;
}

void ARITHMETIC::Real()
{
	double mutiple = 10;
	double real = 0;
	int sign = 1;
	if(current == '+' || current == '-')
	{
		if(current == '+')
		{
			sign = 1;
		}
		else
		{
			sign = -1;
		}
		current = getch();
		if(current != '\b') cout << current;
		pos ++;
	}
	if(!isdigit(current)) throw 1;
	while(isdigit(current))
	{
		real = real * mutiple + (current - '0');
		current = getch();
		if(current != '\b') cout << current;
		pos ++;
		if(real == 0 && isdigit(current))
		{
			throw 1;
		}
	}
	if(current == '.')
	{
		current = getch();
		if(current != '\b') cout << current;
		pos ++;
		mutiple = 0.1;
		while(isdigit(current))
		{
			real += ((current - '0') * mutiple);
			mutiple *= 0.1;
			current = getch();
			if(current != '\b') cout << current;
			pos ++;
		}	
	}
	if(current == '\b' || current == ' ') Space();
	if(current == ')') match --;
	real *= sign;
	opnd.Push(real);
}
			
bool ARITHMETIC::IsOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == ')';
}

char ARITHMETIC::Precede(char c1, char c2)
{
	char value1, value2;
	value1 = Char_value(c1);
	value2 = Char_value(c2);
	if(value1 >= value2)
	{
		return '>';
	}
	else
	{
		return '<';
	}
}

char ARITHMETIC::Char_value(char c)
{
	char value;
	switch(c)
	{
	case '(':
		value = 3;
		break;
	case '*':
		value = 2;
		break;
	case '/':
		value = 2;
		break;
	case '+':
		value = 1;
		break;
	case '-':
		value = 1;
		break;
	case ')':
		value = 0;
		break;
	}
	return value;
}

void ARITHMETIC::Operator(double x, char c, double y)
{
	double result;
	switch(c)
	{
	case '+':
		result = x + y;
		break;
	case '-':
		result = x - y;
		break;
	case '*':
		result = x * y;
		break;
	case '/':
		if(y == 0) throw string ("³ýÁã´íÎó!");
		result = x / y;
		break;
	}
	opnd.Push(result);
}

double ARITHMETIC::Result()
{
	return opnd.Top();
}

void ARITHMETIC::ShowErr()
{
	int i;
	cout << endl;
	for(i = 1; i < pos; i ++)
	{
		cout << '-';
	}
	cout << '^' << endl;
}
