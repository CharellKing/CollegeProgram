#include <iostream>

using namespace std;

#include "LINE.H"

LINE::LINE(int line_size)
{
	if(line_size <= 0)
	{
		line_size = INIT_LINE_SIZE;
	}
	this->line_size = line_size;
	line_length = 0;
	str = new MyString(this->line_size);
}

LINE::LINE(const LINE& x)
{
    line_size = x.line_size;
    line_length = x.line_length;
    str = new MyString(line_size);
    *str = *(x.str);
}

LINE::~LINE()
{
    delete [] str;
}

const LINE& LINE::operator =(const LINE& x)
{
    if(this != &x)
    {
        line_size = x.line_size;
        line_length = x.line_length;
        *str = *(x.str);
    }
    return *this;
}

void LINE::Input()
{
	char c;
	line_length = 0;
	do
	{
        c = cin.get();
        if(c != '\n')
        {
            str->Append(c);
            line_length ++;
        }
    }
    while(c != '\n' && !IsFull());
	cin.sync();
}

void LINE::Append(char c)
{
    if(!IsFull() && c != '\n')
    {
         str->Append(c);
		 line_length ++;
    }
}

/*
istream& operator >>(istream& in, const LINE& x)
{
	char c;
	UINT i = 0;
	while(c = getchar(), c!= '\n' && i < length)
	{
		line.Append(c);
	}
}
*/

void LINE::Output()const
{
	str->Output();
	cout << endl;
}

/*
ostream& operator <<(ostream& out, const LINE& x)
{
	line.Output();
	cout << endl;
}
*/

UINT LINE::Length()const
{
	return line_length;
}

char LINE::operator[](int pos)const
{
    return (*str)[pos];
}

bool LINE::IsFull()const
{
    return line_length == line_size;
}

bool LINE::IsEmpty()const
{
     return line_length == 0;
}

void LINE::Clear()
{
    line_length = 0;
}      
        
    


