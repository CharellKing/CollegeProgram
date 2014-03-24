#include <iostream>

using namespace std;

#include "TEXT.H"

TEXT::TEXT(int text_size, int page_size, int line_size)
{
	UINT i;
	if(text_size <= 0) text_size = INIT_TEXT_SIZE;
	if(page_size <= 0) page_size = INIT_PAGE_SIZE;
	if(line_size <= 0) line_size = INIT_LINE_SIZE;
	text_length = 0;
	this->text_size = text_size;
	this->page_size = page_size;
	this->line_size = line_size;
	a = new page_pointer [text_size];
    a[text_length] = new PAGE(page_size, line_size);
	for(i = 1; i < this->text_size; i ++)
	{
		a[i] = NULL;
	}
    
}

void TEXT::Input()
{
	char c;
	text_length = 0;
	
	do
	{
        c = cin.get();
		Append(c);
	}
    while(!cin.eof() && !IsFull());
	cin.sync();
}

void TEXT::Output()const
{
    UINT i;
    for(i = 0; i < text_length; i ++)
    {
        a[i]->Output();
    }
}

void TEXT::Append(char c)
{
	if(!IsFull())
    {
        a[text_length]->Append(c);
    }
	if(a[text_length]->IsFull())
	{
        text_length ++;
        if(!IsFull())
        {
            a[text_length] = new PAGE(page_size, line_size);
        }
    }
    
}

UINT TEXT::Text_length()
{
	return text_length;
}

bool TEXT::IsFull()const
{
	return text_length == text_size;
}
