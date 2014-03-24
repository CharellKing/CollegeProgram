#ifndef _TEXT_H_

#define _TEXT_H_

#include "PAGE.H"

const UINT INIT_TEXT_SIZE = 500;

class TEXT
{
public:
	typedef PAGE* page_pointer;
	TEXT(int text_size = INIT_TEXT_SIZE, int page_size = INIT_PAGE_SIZE, int line_size = INIT_LINE_SIZE);
	void Input();
	void Output()const;
	void Append(char c);
	UINT Text_length();
	//static void ExpendSpace(page_point* &a, UINT old_size, UINT new_size);
	bool IsFull()const;
protected:
	page_pointer* a;
	UINT text_size, text_length;
	UINT page_size, line_size;
};


#endif
