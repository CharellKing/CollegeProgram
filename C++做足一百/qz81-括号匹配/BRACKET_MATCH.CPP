#include <iostream>

using namespace std;

#include <string>

#include "BRACKET_MATCH.H"

BRACKET_MATCH::BRACKET_MATCH()
{
}

void BRACKET_MATCH::Input()
{
	char c;
	int pos;
	bool result;
	do
	{
		result = true;
		pos = 0;
		while(c = getchar(), c != '\n' && result)
		{
			result = Process(c);
			pos ++;
		}
		cin.sync();
		if(brackets.Length() > 0 && result)
		{
			result = false;
			pos ++;
		}
		if(!result)
		{
			ShowError(pos);
			brackets.Clear();
		}
	}
	while(!result);
}

void BRACKET_MATCH::ShowError(int pos)
{
	int i;
	for(i = 0; i < pos - 1; i ++)
	{
		cout << '-';
	}
	cout << '^' << endl;
}

bool BRACKET_MATCH::Process(char next)
{
	bool result = true;
	if(IsBracket(next))
	{
		char value_top, value_next = BracketValue(next);
		if(brackets.Length() <= 0)
		{
			if(value_next > 0)
			{
				brackets.Push(next);
			}
			else
			{
				result = false;
			}
		}
		else
		{
			value_top = BracketValue(brackets.Top());
			if(value_next > 0)
			{
				if(value_top >= value_next)
				{
					brackets.Push(next);
				}
				else
				{
					result = false;
				}
			}
			else
			{
				if(value_top == -value_next)
				{
					brackets.Pop();
				}
				else
				{
					result = false;
				}
			}
		}
	}
	return result;
}

char BRACKET_MATCH::BracketValue(char c)
{
	char result = c;
	switch(c)
	{
	case '{':
		result = 3;
		break;
	case '[':
		result = 2;
		break;
	case '(':
		result = 1;
		break;
	case ')':
		result = -1;
		break;
	case ']':
		result = -2;
		break;
	case '}':
		result = -3;
		break;
	}
	return result;
}

bool BRACKET_MATCH::IsBracket(char c)
{
	return c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}';
}

