#include <iostream>

using namespace std;

#include <conio.h>

#include <cstring>

#include "STUDENT.H"

void STUDENT::SetSlid()
{
	int i = 0;
	char c;
	c = getch();
	while( c = getch(), i < 10)
	{
		if(isdigit(c)) slid[i++] = c, cout << c;
	}
	slid[i] = '\0';
	cout << endl;
}

char* STUDENT::GetSlid()
{
	return slid;
}
	