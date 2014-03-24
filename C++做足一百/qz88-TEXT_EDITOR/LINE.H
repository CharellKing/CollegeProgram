#ifndef _LINE_H_

#define _LINE_H_

#include "Char_Str.h"

const UINT INIT_LINE_SIZE = 50;

class LINE
{
public:
	LINE(int line_size = INIT_LINE_SIZE);
	LINE(const LINE& x);
	~LINE();
	const LINE& operator =(const LINE& x);
	void Input();
	void Append(char c);
	//friend istream& operator >>(istream& in, const LINE& x);
	void Output()const;
	//friend ostream& operator <<(ostream& out, const LINE& x);
	UINT Length()const;
	char operator[](int pos)const;
	bool IsFull()const;
	bool IsEmpty()const;
	void Clear();
protected:
	MyString *str;
	UINT line_length, line_size;
};


#endif
