#include <iostream>

using namespace std;

//#include <cctype>

#include <conio.h>


char Menu(const char *menuItems, const char *item)
{
	char c; 
	cout << menuItems;
	while(!strchr(menuItems, c = getch())) putchar('\a');
	putchar(c);
	cout << endl;
	return c;
}
