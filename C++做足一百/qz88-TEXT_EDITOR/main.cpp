#include <iostream>

using namespace std;

#include <conio.h>

//#include "LINE.H"

//#include "PAGE.H"

#include "TEXT.H"

int main()
{
    /*
	LINE a(12);
    a.Input();
    a.Output();
    LINE b;
    b = a;
    b.Output();
    getch();
    */
    /*
	PAGE a(5, 12);
	a.Input();
	a.Output();
	getch();
	*/
	TEXT a(5, 5, 12);
	a.Input();
	a.Output();
	getch();
	return 0;
}
