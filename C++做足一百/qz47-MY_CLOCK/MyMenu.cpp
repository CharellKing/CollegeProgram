#include <iostream.h>

#include <stdio.h>

#include <ctype.h>

#include <conio.h>

#include <string.h>

#include "MyMenu.h"

#include "BOOL.H"

char Menu(const char *menuItem, const char *Item)
{
	char c;
	cout << menuItem;
	while(!(strchr(Item, c = toupper(getch())))) putchar('\a');
	cout << c <<endl;
	return c;
}