#include <iostream>

using namespace std;

#include <conio.h>

#include <cstring>

#include "PEOPLE.H"

#include "MyMenu.h"

void PEOPLE::SetId()
{
	char c;
	char first = 0;
	while(c = getch(), first < 16)
	{
		if(isdigit(c) || isalpha(c)) id[first ++] = c, cout << c;
	}
	id[first] = '\0';
	cout << endl;
}

void PEOPLE::SetName()
{
	cin >> name;
}

void PEOPLE::SetGender()
{
	'M' == Menu("M - ÄÐ, F - Å®", "MF") ? gender = true : gender = false;
}

void PEOPLE::SetBirth()
{
	birth.Input();
}

char* PEOPLE::GetId()
{
	return id;
}

char* PEOPLE::GetName()
{
	return name;
}

bool PEOPLE::GetGender()
{
	return gender;
}

MYDATE PEOPLE::GetBirth()
{
	return birth;
}

void PEOPLE::Birth()
{
	birth.Output();
}
