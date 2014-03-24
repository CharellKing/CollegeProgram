#ifndef _PAGE_H_

#define _PAGE_H_

#include "LINE.H"

#include "Container.h"

const UINT INIT_PAGE_SIZE = 24;

class PAGE
{
public:
    typedef LINE* line_point;
	PAGE(UINT page_size = INIT_PAGE_SIZE, UINT line_size = INIT_LINE_SIZE);
	void Input();
	//friend istream& operator <<(istream& in, LINKLIST<LINE>& x);
	void Output()const;
	void Append(char c);
	//friend ostream& operator <<(ostream& out, const LINKLIST<LINE>& x);
	UINT Page_length();
	bool IsFull()const;
protected:
	line_point* a;
	UINT page_size, page_length;
    UINT line_size;
};


#endif
