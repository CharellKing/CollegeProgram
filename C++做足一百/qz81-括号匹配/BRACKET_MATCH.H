#ifndef _BRACKET_MATCH_H_

#define _BRACKET_MATCH_H_

#include "STACK.H"

class BRACKET_MATCH
{
public:
	BRACKET_MATCH();
	void Input();
	bool Process(char c);
	static char BracketValue(char c);
	static bool IsBracket(char c);
	static void ShowError(int pos);
protected:
	STACK<char> brackets;
};
#endif