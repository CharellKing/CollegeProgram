#include <iostream>

using namespace std;

#include <cctype>

#include <conio.h>

#include "MyMenu.h"

char Menu(const char *menuItem, const char *Item)
{
	char c;
	cout << menuItem;
	while(!(strchr(Item, c = toupper(getch())))) putchar('\a');
	cout << c <<endl;
	return c;
}