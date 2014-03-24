#include <iostream>
using namespace std;

#include "PAGE.H"

PAGE::PAGE(UINT page_size, UINT line_size)
{
   if(page_size <= 0) page_size = INIT_PAGE_SIZE;
   if(line_size <= 0) line_size = INIT_LINE_SIZE;
   this->page_size = page_size;
   this->line_size = line_size;
   page_length = 0;
   a = new line_point[page_size];
   a[page_length] = new LINE(line_size);
}

void PAGE::Input()
{
    page_length = 0;
    char c;
    do
    {
        c = cin.get();
        Append(c); 
    }
    while(!IsFull() && !cin.eof());
	cin.sync();
}
        
void PAGE::Output()const
{
     UINT i;
	 for(i = 0; i < page_length; i ++)
	 {
		 a[i]->Output();
	 }
}

void PAGE::Append(char c)
{
	
    if(!IsFull()) a[page_length]->Append(c);
    if(c == '\n' || a[page_length]->IsFull())
    {
         page_length ++;
         if(!IsFull())
         {
             a[page_length] = new LINE(line_size);
         }
    }
}

UINT PAGE::Page_length()
{
    return page_length;
}

bool PAGE::IsFull()const
{
    return page_size == page_length;
}
